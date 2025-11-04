# Check if Array is Sorted

## Problem Statement

Given an array of integers `A`, determine whether the array is sorted in **non-decreasing order** (ascending order with duplicates allowed).

Return:
- `1` if the array is sorted
- `0` if the array is not sorted

---

## Examples

### Example 1:
**Input:**
```
A = [1, 2, 3, 4, 5]
```
**Output:**
```
1
```
**Explanation:** The array is sorted in ascending order.

---

### Example 2:
**Input:**
```
A = [1, 4, 6, 3, 9, 7]
```
**Output:**
```
0
```
**Explanation:** The array is not sorted. Element 6 is followed by 3 (6 > 3), violating the sorted property.

---

### Example 3:
**Input:**
```
A = [5, 5, 5, 5]
```
**Output:**
```
1
```
**Explanation:** Array with duplicate elements is considered sorted (non-decreasing).

---

### Example 4:
**Input:**
```
A = []
```
**Output:**
```
1
```
**Explanation:** An empty array is considered sorted by definition.

---

### Example 5:
**Input:**
```
A = [42]
```
**Output:**
```
1
```
**Explanation:** A single element array is always sorted.

---

## Constraints

- `0 ≤ A.length ≤ 10^5`
- `-10^9 ≤ A[i] ≤ 10^9`

---

## Approach

### Intuition
To check if an array is sorted, we need to verify that every element is less than or equal to the next element. If we find any element that is greater than the next element, the array is not sorted.

### Algorithm
1. Handle edge case: Empty array is sorted
2. Iterate through the array from index 0 to n-2
3. Compare each element `A[i]` with the next element `A[i+1]`
4. If `A[i] > A[i+1]`, return 0 (not sorted)
5. If we complete the loop without finding violations, return 1 (sorted)

### Why `i < A.size() - 1`?
We use `A.size() - 1` because we're checking `A[i+1]`. If we go up to `A.size()`, we'd access out-of-bounds memory when checking the last element's next element.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
  - We traverse the array once
  - Each comparison takes O(1) time
  
- **Space Complexity:** `O(1)`
  - We only use a loop counter variable
  - No extra data structures needed

---

## Edge Cases to Consider

1. **Empty array** → Should return 1 (sorted by definition)
2. **Single element** → Should return 1 (trivially sorted)
3. **All duplicates** → Should return 1 (e.g., [5, 5, 5, 5])
4. **Decreasing order** → Should return 0 (e.g., [5, 4, 3, 2, 1])
5. **Negative numbers** → Should work correctly (e.g., [-5, -3, -1, 0, 2])

---

## Follow-Up Questions

1. **How would you modify this to check for strictly increasing order?**
   - Change condition from `A[i] < A[i+1]` to `A[i] >= A[i+1]`

2. **Can you check if array is sorted in descending order?**
   - Check if `A[i] > A[i+1]` instead

3. **What if we need to return the index where sorting breaks?**
   - Return `i` instead of 0 when violation found

4. **How would you handle very large arrays efficiently?**
   - Early termination (which we already do)
   - Parallel processing for massive datasets

---

## Related Problems

- Check if array is sorted in descending order
- Find the first index where array is not sorted
- Count inversions in array
- Merge two sorted arrays
- Sort an array with minimum swaps

---

## Implementation Notes

- Use `size_t` for loop variable to avoid signed/unsigned comparison warnings
- Pass vector by reference to avoid copying
- Consider using `const` if you don't modify the array
- The `-1` in loop condition is crucial to prevent out-of-bounds access
