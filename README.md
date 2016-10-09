# pairing-heap
A c++ implementation of the Two-Pass Pairing Heap data structure. This is a basic implementation of a min-heap of integers but it can be easily modified to support other types of keys or to make it a max-heap instead. A template-based implementation would be nice to have.

# API
* `PairingHeap heap; // Create new empty min-heap`
* `heap.Empty(); // True if heap is empty`
* `heap.Top(); // Return element with minimum key`
* `heap.Push(int); // Insert new element`
* `heap.Pop(); // Remove element with minimum key`
* `heap.Join(); // Merge two heaps together`

# Time Complexity
* `Empty`, `Top`, `Push`, and `Join` take `O(1)` time in the worst case.
* `Pop` takes `O(lg N)` time amortized over a sequence of operations.
