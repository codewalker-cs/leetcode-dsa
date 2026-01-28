/*
===========================================================
File: search_range.cpp
Problem: Find First and Last Position of Element in Sorted Array

Intuition:
-----------
The array is sorted, so Binary Search is the optimal approach.

However, a normal binary search only tells us *if* the target exists,
not *where its range starts and ends*.

So we do **two binary searches**:

1. First Binary Search (Left Boundary):
   - When nums[mid] == target, we do NOT stop.
   - We store mid as a potential answer.
   - Then we move left (end = mid - 1) to find an earlier occurrence.

2. Second Binary Search (Right Boundary):
   - When nums[mid] == target, we again store mid.
   - Then we move right (start = mid + 1) to find a later occurrence.

Why this works:
---------------
Binary search ensures O(log n) time.
Doing it twice still keeps total complexity O(log n).

Edge Case:
----------
If target is not found, both first and last remain -1.

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1) (no extra space used)

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int n = nums.size();

        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        start = 0;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return {first, last};
    }
};
