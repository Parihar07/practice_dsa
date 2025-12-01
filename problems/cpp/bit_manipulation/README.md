# Bit Manipulation

Bitwise operations and bit tricks for efficient problem solving.

## Key Concepts Covered
- Bitwise operators (&, |, ^, ~, <<, >>)
- Set, clear, toggle, and check bits
- Count set bits (Kernighan's algorithm)
- XOR properties and applications
- Bit masking
- Power of 2 checks
- Binary string operations

## Problems in this Directory

### Counting Bits
- [bm_countSetBits](bm_countSetBits/) - Count total set bits
- [bm_count_set_bits](bm_count_set_bits/) - Count set bits variant

### Single Number Problems
- [bm_single_number](bm_single_number/) - Find single number (others appear twice)
- [bm_thriceNumbers](bm_thriceNumbers/) - Find number appearing once (others thrice)

### Binary String Operations
- [bm_add_binary_string](bm_add_binary_string/) - Add two binary strings

### Bitwise Operations
- [bm_subarray_or](bm_subarray_or/) - Subarray OR operations
- [bm_unset_xbitsright](bm_unset_xbitsright/) - Unset X rightmost bits
- [bm_compression_problem](bm_compression_problem/) - Compression using bits

## Tips
- XOR is super useful: a^a=0, a^0=a
- Use & 1 to check if number is odd
- Use << and >> for fast multiplication/division by 2
- ~n equals -(n+1) in two's complement
- Practice bit manipulation—it's often the key to O(1) solutions
