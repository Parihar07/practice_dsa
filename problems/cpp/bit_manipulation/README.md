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
- [bm_count_set_bits](bm_count_set_bits/) - Count 1s in binary representation
- [bm_single_number](bm_single_number/) - Find single number using XOR
- [bm_thrice_numbers](bm_thrice_numbers/) - Number appearing once (others thrice)
- [bm_add_binary_string](bm_add_binary_string/) - Binary string addition
- [bm_subarray_or](bm_subarray_or/) - Subarray OR operations
- [bm_unset_xbitsright](bm_unset_xbitsright/) - Unset rightmost X bits
- [bm_compression_problem](bm_compression_problem/) - Bit compression

## Tips
- XOR is super useful: a^a=0, a^0=a
- Use & 1 to check if number is odd
- Use << and >> for fast multiplication/division by 2
- ~n equals -(n+1) in two's complement
- Practice bit manipulation—it's often the key to O(1) solutions
