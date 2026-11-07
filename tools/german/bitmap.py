"""Indexed PNG and Nintendo packed-pixel helpers without external libraries."""

import struct
import zlib


def write_png(path, width, height, pixels, colors=16):
    def chunk(kind, data):
        return struct.pack(">I", len(data)) + kind + data + struct.pack(">I", zlib.crc32(kind + data))
    palette = bytes(component for i in range(256) for component in (round(min(i, colors-1) * 255 / (colors-1)),) * 3)
    rows = b"".join(b"\0" + bytes(pixels[y*width:(y+1)*width]) for y in range(height))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0))
                     + chunk(b"PLTE", palette) + chunk(b"IDAT", zlib.compress(rows, 9)) + chunk(b"IEND", b""))


def read_png(path):
    data = path.read_bytes()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError(f"Not a PNG: {path}")
    offset, compressed = 8, bytearray()
    while offset < len(data):
        length = struct.unpack_from(">I", data, offset)[0]
        kind, payload = data[offset+4:offset+8], data[offset+8:offset+8+length]
        if kind == b"IHDR":
            width, height, depth, color, compression, filtering, interlace = struct.unpack(">IIBBBBB", payload)
            if color != 3 or depth not in (1, 2, 4, 8) or interlace:
                raise ValueError(f"Keep {path} as a non-interlaced indexed PNG")
        elif kind == b"IDAT":
            compressed.extend(payload)
        offset += 12 + length
    raw = zlib.decompress(compressed)
    stride = (width * depth + 7) // 8
    previous, pixels = bytearray(stride), []
    for y in range(height):
        filter_type = raw[y*(stride+1)]
        row = bytearray(raw[y*(stride+1)+1:(y+1)*(stride+1)])
        for x in range(stride):
            left, above, corner = (row[x-1] if x else 0), previous[x], (previous[x-1] if x else 0)
            if filter_type == 1:
                prediction = left
            elif filter_type == 2:
                prediction = above
            elif filter_type == 3:
                prediction = (left + above) // 2
            elif filter_type == 4:
                p = left + above - corner
                distances = [abs(p-left), abs(p-above), abs(p-corner)]
                prediction = (left, above, corner)[distances.index(min(distances))]
            elif filter_type == 0:
                prediction = 0
            else:
                raise ValueError("Invalid PNG filter")
            row[x] = (row[x] + prediction) & 255
        pixels.extend((row[x*depth//8] >> (8-depth-(x*depth)%8)) & ((1<<depth)-1) for x in range(width))
        previous = row
    return width, height, pixels


def unpack_pixels(data, depth):
    return [(byte >> shift) & ((1 << depth)-1) for byte in data for shift in range(0, 8, depth)]


def pack_pixels(pixels, depth):
    if any(p < 0 or p >= 1 << depth for p in pixels):
        raise ValueError(f"Image uses palette indices beyond {depth}-bit color")
    return bytes(sum(pixels[i+j] << (j*depth) for j in range(8//depth)) for i in range(0, len(pixels), 8//depth))


def tiles_to_png(path, data, depth, columns):
    values = unpack_pixels(data, depth)
    tiles = len(values) // 64
    if tiles % columns:
        raise ValueError("Incomplete tile row")
    width, height = columns * 8, tiles // columns * 8
    pixels = [0] * (width * height)
    for tile in range(tiles):
        tx, ty = tile % columns * 8, tile // columns * 8
        for y in range(8):
            pixels[(ty+y)*width+tx:(ty+y)*width+tx+8] = values[tile*64+y*8:tile*64+y*8+8]
    write_png(path, width, height, pixels, 1 << depth)


def png_to_tiles(path, depth):
    width, height, pixels = read_png(path)
    if width % 8 or height % 8:
        raise ValueError("Tile image dimensions must be multiples of eight")
    values = []
    for ty in range(0, height, 8):
        for tx in range(0, width, 8):
            for y in range(8):
                values.extend(pixels[(ty+y)*width+tx:(ty+y)*width+tx+8])
    return pack_pixels(values, depth)
