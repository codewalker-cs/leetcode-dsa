# Time Complexity vs Input Size Reference

| Input Size (N) | Maximum Allowed Complexity | Example Algorithms |
|---------------|---------------------------|-------------------|
| N ≤ 10 | O(N!) | Generating all permutations |
| N ≤ 20 | O(2^N) | Exhaustive search, Recursion |
| N ≤ 500 | O(N³) | Simple triple nested loops |
| N ≤ 5,000 | O(N²) | Bubble Sort, Selection Sort |
| N ≤ 10⁵ | O(N log N) | Merge Sort, Heap Sort, `std::sort()` |
| N ≤ 10⁷ | O(N) | Linear Search, Kadane’s Algorithm, Hashing |
| N = Very Large | O(log N) | Binary Search |

> This table serves as a quick reference for selecting the optimal algorithm based on input size constraints in competitive programming and interviews.
