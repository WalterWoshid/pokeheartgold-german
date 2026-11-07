#!/usr/bin/env python3
"""Render regional data tables with named labels and symbolic pointers."""
import struct


def render(data,base,start,end,names,labels,numeric_values=()):
    result=[]
    ordered=sorted((a,n) for a,n in labels.items() if start<=a<end)
    for i,(address,name) in enumerate(ordered):
        stop=ordered[i+1][0] if i+1<len(ordered) else end
        result.extend(['\t.global '+name,name+':'])
        while address<stop:
            if address%4==0 and address+4<=stop:
                value=struct.unpack_from('<I',data,address-base)[0]
                if 0x02000000<=value<0x02400000 and value not in numeric_values:
                    if value&~1 not in names:raise ValueError(f'Unresolved pointer at {address:08X}: {value:08X}')
                    literal=names[value&~1]
                else:literal=f'0x{value:08X}'
                result.append('\t.word '+literal);address+=4
            elif address%2==0 and address+2<=stop:
                value=struct.unpack_from('<H',data,address-base)[0]
                result.append(f'\t.short 0x{value:04X}');address+=2
            else:
                result.append(f'\t.byte 0x{data[address-base]:02X}');address+=1
        result.extend(['\t.size '+name+',.-'+name,''])
    return '\n'.join(result)
