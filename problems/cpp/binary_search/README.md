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

### Basic Binary Search
- [bs_searchinrange](bs_searchinrange/) - Search element in range
- [bs_sortedinsert](bs_sortedinsert/) - Find insertion position in sorted array
- [bs_square_root](bs_square_root/) - Calculate square root using binary search
- [bs_peak_number](bs_peak_number/) - Find peak element

### Binary Search on Answer
- [bs_aggeresivecows](bs_aggeresivecows/) - Aggressive cows (maximize minimum distance)
- [bs_painterpartition](bs_painterpartition/) - Painter's partition problem
- [bs_targetinksortedarray](bs_targetinksortedarray/) - Search in K sorted arrays

### Tree-Based
- [checkIfBST](checkIfBST/) - Check if tree is valid BST

## Tips
- Always maintain the invariant
- Watch for integer overflow (use mid = l + (r-l)/2)
- Think about what "sorted" means in the problem
- Binary search on answer when checking is easier than finding
- Practice both iterative and recursive approaches
