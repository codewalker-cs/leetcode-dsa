/*
Intuition:
This is a classic binary search problem.

We search for the target in a sorted array.
If we find it → return its index.
If we don't → return the position where it should be inserted
to maintain sorted order.

Binary search invariant:
When the loop ends, 'l' is the correct insertion index.

Why return l?
Because l always points to the first index where target
can legally be placed.

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};
