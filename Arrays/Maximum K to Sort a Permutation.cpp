/*
Intuition:
- The goal is to find the bitwise AND of all elements that are
  not already at their correct indices.
- If nums[i] == i, that element is already correctly positioned
  and does not contribute to the answer.
- If every element is already at its correct index, the answer is 0.

Approach:
1. Initialize ans = -1, which has all bits set to 1.
2. Traverse the array.
3. If nums[i] != i, update ans using bitwise AND with nums[i].
4. Return max(0, ans) to handle the case where no elements need
   to be considered.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        return max(0, ans);
    }
};
