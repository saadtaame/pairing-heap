# pairing-heap
A c++ implementation of the Two-Pass Pairing Heap data structure. This is a basic implementation of a min-heap of integers but it can be easily modified to support other types of keys or to make it a max-heap instead. A template-based implementation would be nice to have.

# API
* `PairingHeap heap; // Create new empty min-heap`
* `heap.Empty(); // True if heap is empty`
* `heap.Top(); // Returns minimum`
* `heap.Push(int); // Insert new element`
* `heap.Pop(); // Remove minimum element`
* `heap.Join(); // Merge two heaps together`
