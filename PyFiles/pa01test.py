import hashlib
from pathlib import Path


def calculate_checksum(file_path, bit_size):
    max_value = 2 ** bit_size
    checksum = 0

    with open(file_path, 'rb') as f:
        while byte := f.read(1):
            checksum += int.from_bytes(byte, 'little')
            checksum %= max_value  

    return checksum



folder = Path('pa01nFiles')

for file_path in folder.iterdir():
    if file_path.is_file():
        print(f"File: {file_path.name}")
        for size in [8, 16, 32]:
            checksum = calculate_checksum(file_path, size)
            print(f"  {size}-bit checksum: {checksum}")
        print()