# Binary Search

Binary search algorithms and their variations.

## Key Concepts Covered
- Binary search on sorted arrays
- Binary search on answer space
- Lower bound and upper bound
- Search in rotated arrays
- Peak finding
- Allocation problems (painter's partition, aggressive cows)
- Square root using binary search

## Problems in this Directory
- `bs_sortedinsert/` - Find position in sorted array
- `bs_searchinrange/` - Search in range
- `bs_peak_number/` - Find peak element
- `bs_square_root/` - Calculate square root using BS
- `bs_targetinksortedarray/` - Search in K-sorted array
- `bs_aggeresivecows/` - Aggressive cows problem
- `bs_painterpartition/` - Painter's partition problem
- And more...

## Tips
- Always maintain the invariant
- Watch for integer overflow (use mid = l + (r-l)/2)
- Think about what "sorted" means in the problem
- Binary search on answer when checking is easier than finding
- Practice both iterative and recursive approaches
