import sys

def calculate_checksum(file_path, bit_size):
    with open(file_path, 'rb') as f:
        byte_data = f.read()

    total = 0
    step = bit_size // 8

    for i in range(0, len(byte_data), step):
        chunk = byte_data[i:i+step]
        value = int.from_bytes(chunk, byteorder='big', signed=False)
        total += value

    # Limit total to bit size (no overflow)
    max_val = (1 << bit_size) - 1
    total &= max_val

    # Compute two's complement
    checksum = (~total + 1) & max_val
    return checksum

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: python3 pa01.py inputFilename.txt checksumSize")
        sys.exit(1)

    file_path = sys.argv[1]
    bit_size = int(sys.argv[2])

    if bit_size not in (8, 16, 32):
        print("Error: checksum size must be 8, 16, or 32")
        sys.exit(1)

    checksum = calculate_checksum(file_path, bit_size)
    print(f"{bit_size}-bit checksum: {hex(checksum)[2:]}")
    print(f"{bit_size}-bit checksum bin: {bin(checksum)[2:]}")
