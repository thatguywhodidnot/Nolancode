
'''
============================================================================
| Assignment: pa01 - Calculate the checksum of an input file given:
| -> the name of the input file,
| -> the checksum size of either 8, 16, or 32 bits
| Author: Nolan Milligan
| Language: python
| To Compile: (no compilation needed for Python)
| To Execute: python3 pa01.py inputFilename.txt checksumSize
| where inputFilename.txt is the input file
| and checksumSize is either 8, 16, or 32
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
| Class: CIS3360 - Security in Computing - Spring 2025
| Instructor: McAlpin
| Due Date: per assignment
============================================================================
'''


import sys
import textwrap
from pathlib import Path


def calculate_checksum(file_path, bit_size):
    if bit_size not in (8, 16, 32):
        raise ValueError("Bit size must be 8, 16, or 32")

# determines how checksum will be organized by bit size

    byte_width = bit_size // 8
    max_value = 2 ** bit_size
    checksum = 0

# opens file and reads raw bytes and then creates dataset from those bytes
    with open(file_path, 'rb') as f:
        data = f.read()
    with open(file_path, 'r') as l:
        content = l.read()
        char_count = len(content)

# Used modulus of the data length and the byte width to find result.
    add_char = 0
    remainder = len(data) % byte_width
    if remainder != 0:  # checks if padding is needed and adds it
        pad_len = byte_width - remainder
        add_char += pad_len
        pad_byte = b'X'
        data += pad_byte * pad_len

    for i in range(0, len(data), byte_width):
        chunk = data[i:i + byte_width]
        endian = 'little' if bit_size == 8 else 'big'
        value = int.from_bytes(chunk, endian)
        checksum = (checksum + value) % max_value

    checksum_hex = hex(checksum)[2:].zfill(byte_width * 2)
    if str(checksum_hex)[0] == '0':
        checksum_hex = int(str(checksum_hex)[1:])

    def wrapped_wrap(content, width=80):
        return '\n'.join(content[i:i+width] for i in range(0, len(content), width))

    print(
        f"\n{wrapped_wrap(content)}{'X'*add_char if remainder != 0 else ''}\n{bit_size} bit checksum is {checksum_hex} for all {char_count+add_char} chars")

    return checksum


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 pa01.py inputFilename.txt bitSize")
        sys.exit(1)

    file_path = Path(sys.argv[1])
    bit_size = int(sys.argv[2])

    try:
        calculate_checksum(file_path, bit_size)
    except Exception as e:
        print(f"Error: {e}")

'''
=============================================================================
| I Nolan Milligan (no606206) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
=============================================================================
'''
