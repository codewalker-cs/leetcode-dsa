/*
Intuition:
- In each move, we can increment or decrement an element by 1.
- To minimize the total number of moves, we should make all elements
  equal to the median.
- The median minimizes the sum of absolute differences between
  all array elements and the target value.

Approach:
1. Sort the array.
2. Select the middle element as the median: nums[n / 2].
3. Calculate the absolute difference between every element and
   the median.
4. Add all differences and return the result.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) auxiliary space (ignoring sorting stack space).
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = nums[n / 2];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += abs(nums[i] - m);
        }

        return ans;
    }
};
