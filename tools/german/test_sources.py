"""Checks for editable bitmap layout and the LZ11 match-length boundary."""

import os
from pathlib import Path
import tempfile
import unittest

from bitmap import png_to_tiles, read_png, tiles_to_png, write_png
from source_assets import run


class SourceTests(unittest.TestCase):
    def test_tile_coordinates_and_editing(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "tiles.png"
            original = bytes([0] * 32 + [0x11] * 32 + [0x22] * 32 + [0x33] * 32)
            tiles_to_png(path, original, 4, 2)
            width, height, pixels = read_png(path)
            self.assertEqual((width, height), (16, 16))
            self.assertEqual([pixels[y*width+x] for x, y in [(0, 0), (8, 0), (0, 8), (8, 8)]], [0, 1, 2, 3])
            self.assertEqual(png_to_tiles(path, 4), original)
            pixels[-1] = 1
            write_png(path, width, height, pixels)
            self.assertEqual(png_to_tiles(path, 4), original[:-1] + b"\x13")

    def test_2bit_texture_editing(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "texture.png"
            original = bytes(range(256))
            tiles_to_png(path, original, 2, 4)
            self.assertEqual(png_to_tiles(path, 2), original)

    def test_lz11_length_boundary(self):
        nitrogfx = Path(os.environ.get("NITROGFX", "build/heartgold.de/tools/nitrogfx/nitrogfx"))
        if not nitrogfx.is_file():
            self.skipTest("Set NITROGFX to the native nitrogfx executable")
        with tempfile.TemporaryDirectory() as temporary:
            source, target = Path(temporary) / "data.raw", Path(temporary) / "data.lz"
            for length in (271, 272, 273):
                source.write_bytes(bytes(range(256)) + bytes(i % 256 for i in range(length)))
                run(nitrogfx.resolve(), source, target, ["-extfmt", "-nopad"])
                data, position, lengths = target.read_bytes(), 4, []
                while position < len(data):
                    flags = data[position]
                    position += 1
                    for bit in range(7, -1, -1):
                        if position >= len(data):
                            break
                        if flags & (1 << bit):
                            code = data[position] >> 4
                            if code == 0:
                                count = ((data[position] & 15) << 4 | data[position+1] >> 4) + 17
                                position += 3
                            elif code == 1:
                                count = ((data[position] & 15) << 12 | data[position+1] << 4 | data[position+2] >> 4) + 273
                                position += 4
                            else:
                                count = code + 1
                                position += 2
                            lengths.append(count)
                        else:
                            position += 1
                self.assertEqual(lengths, [length], str(nitrogfx.resolve()))


if __name__ == "__main__":
    unittest.main()
