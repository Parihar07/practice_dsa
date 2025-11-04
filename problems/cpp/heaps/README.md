# Heaps

Priority queues, heap data structures, and heap algorithms.

## Key Concepts Covered
- Min heap and max heap
- Priority queue operations
- Heapify algorithm
- Heap sort
- K-th largest/smallest element
- Median finding with two heaps
- Top K problems
- Merge K sorted arrays/lists

## Tips
- Use priority_queue<int> for max heap (default)
- Use priority_queue<int, vector<int>, greater<int>> for min heap
- Heaps are perfect for "best K" problems
- Two heaps technique for running median
- Heapify is O(n), building heap one by one is O(n log n)
