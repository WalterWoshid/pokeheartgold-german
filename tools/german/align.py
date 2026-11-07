#!/usr/bin/env python3
"""Locate corresponding routines across regional builds using instruction sequences."""
import argparse
from collections import Counter
from difflib import SequenceMatcher
import json
from pathlib import Path
import re
import subprocess
from compare import elf_symbols


def instructions(path, base):
    output = subprocess.check_output(['arm-none-eabi-objdump','-D','-b','binary','-m','arm','-M','force-thumb',f'--adjust-vma={base}',str(path)], text=True)
    result=[]
    for line in output.splitlines():
        m=re.match(r'\s*([0-9a-f]+):\s+(?:[0-9a-f]{4}\s+){1,2}\s*([a-z][a-z0-9.]*)\s*(.*)',line)
        if not m: continue
        address=int(m[1],16)
        op=m[2].removesuffix('.n').removesuffix('.w')
        args=m[3].split(';')[0].strip()
        if re.fullmatch(r'0x[0-9a-f]+',args): args='TARGET'
        if '[pc,' in args: args=args.split(',')[0]+', PC'
        result.append((address,op+' '+args))
    return result


def align(actual, expected):
    # Unique eight-instruction windows anchor the long identical spans.
    width=8
    def windows(seq):
        return [tuple(x[1] for x in seq[i:i+width]) for i in range(len(seq)-width+1)]
    a,b=windows(actual),windows(expected)
    ca,cb=Counter(a),Counter(b)
    lookup={token:i for i,token in enumerate(b) if cb[token]==1}
    pairs=[(i,lookup[token]) for i,token in enumerate(a) if ca[token]==1 and token in lookup]
    # Longest increasing subsequence retains source order around repeated routines.
    import bisect
    tails=[]; ends=[]; previous=[]
    for n,(i,j) in enumerate(pairs):
        k=bisect.bisect_left(tails,j)
        previous.append(ends[k-1] if k else -1)
        if k==len(tails): tails.append(j);ends.append(n)
        else: tails[k]=j;ends[k]=n
    chain=[]
    n=ends[-1] if ends else -1
    while n>=0: chain.append(pairs[n]);n=previous[n]
    chain.reverse()
    matches={}
    for i,j in chain:
        for k in range(width): matches[i+k]=j+k
    # Align short gaps exactly after the anchors establish local context.
    boundaries=[(-1,-1)]+sorted(matches.items())+[(len(actual),len(expected))]
    for (i,j),(ni,nj) in zip(boundaries,boundaries[1:]):
        if 1<ni-i<600 and 1<nj-j<600:
            matcher=SequenceMatcher(None,[x[1] for x in actual[i+1:ni]],[x[1] for x in expected[j+1:nj]],autojunk=False)
            for block in matcher.get_matching_blocks():
                for k in range(block.size):matches[i+1+block.a+k]=j+1+block.b+k
    return {actual[i][0]:expected[j][0] for i,j in matches.items()}


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('build',type=Path);p.add_argument('reference',type=Path);p.add_argument('module');p.add_argument('--output',type=Path,required=True);p.add_argument('--names-output',type=Path);p.add_argument('--reference-base',type=lambda value:int(value,0))
    args=p.parse_args()
    symbols=elf_symbols(args.build/'main.nef')
    base=min(s['address'] for s in symbols[args.module] if s['address']>=0x2000000)
    text_end=max(s['address']+s['size'] for s in symbols[args.module] if s['type']==2)
    actual=instructions(args.build/(args.module+'.sbin'),base)
    reference_base=args.reference_base if args.reference_base is not None else base
    expected=instructions(args.reference,reference_base)
    mapping=align(actual,expected)
    funcs=[]
    for symbol in symbols[args.module]:
        if symbol['type'] != 2 or symbol['name'].startswith(('.','$','SDK_')) or not(base<=symbol['address']<text_end): continue
        addr=symbol['address']&~1
        if addr in mapping: target=mapping[addr]; confidence='matched'
        else:
            nearby=min(mapping,key=lambda x:abs(x-addr))
            target=addr+mapping[nearby]-nearby; confidence=f'inferred {nearby-addr:+d}'
        funcs.append(dict(symbol,target=target,confidence=confidence))
    args.output.write_text(json.dumps(funcs,indent=2)+'\n')
    if args.names_output:
        names={}
        for module in ('main','ITCM','DTCM'):
            for symbol in elf_symbols(args.build/'main.nef',True).get(module,[]):
                if not symbol['name'].startswith(('.','$','SDK_')) and symbol['address']>=0x2000000: names.setdefault(symbol['address']&~1,symbol['name'])
        for symbol in funcs: names.setdefault(symbol['target'],symbol['name'])
        source_names={s['address']&~1:s['name'] for s in symbols[args.module] if not s['name'].startswith(('.','$'))}
        a=(args.build/(args.module+'.sbin')).read_bytes(); b=args.reference.read_bytes()
        import struct
        for src,dst in mapping.items():
            if src-base+2>len(a) or dst-reference_base+2>len(b):continue
            x,y=struct.unpack_from('<H',a,src-base)[0],struct.unpack_from('<H',b,dst-reference_base)[0]
            if x&0xF800==0x4800 and y&0xF800==0x4800:
                ap=((src+4)&~3)+(x&255)*4-base;bp=((dst+4)&~3)+(y&255)*4-reference_base
                if ap+4>len(a) or bp+4>len(b):continue
                av,bv=struct.unpack_from('<I',a,ap)[0],struct.unpack_from('<I',b,bp)[0]
                if av&~1 in source_names: names.setdefault(bv&~1,source_names[av&~1])
        args.names_output.write_text(json.dumps({hex(k):v for k,v in names.items()},indent=2)+'\n')
    for s in funcs:
        print(f"{s['name']:40} {s['address']:08X} -> {s['target']:08X} {s['size']:5} {s['confidence']}")

if __name__=='__main__':main()
