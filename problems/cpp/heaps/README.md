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

## Problems in this Directory

### Heap Implementation
- [maxheap](maxheap/) - Max heap implementation
- [minHeap](minHeap/) - Min heap implementation
- [heap_build_heap](heap_build_heap/) - Build heap from array

### Heap Applications
- [heap_magicianChocolatesKid](heap_magicianChocolatesKid/) - Magician and chocolates kid
- [heap_connectingropes](heap_connectingropes/) - Connecting ropes with minimum cost
- [heap_product0f3](heap_product0f3/) - Product of 3 largest elements
- [heap_heap_query](heap_heap_query/) - Heap queries

## Common Patterns
- K largest/smallest: Use heap of size K
- Running median: Use two heaps (max heap for lower half, min heap for upper half)
- Merge K sorted: Use min heap with K elements

## Tips
- Use priority_queue<int> for max heap (default)
- Use priority_queue<int, vector<int>, greater<int>> for min heap
- Heaps are perfect for "best K" problems
- Two heaps technique for running median
- Heapify is O(n), building heap one by one is O(n log n)
