/*
Intuition:
We want the maximum sum of a contiguous subarray.

At each index, we decide:
1) Start a new subarray from the current element, OR
2) Extend the previous subarray by adding the current element.

currentSum stores the maximum subarray sum ending at the current index.
maxSum stores the maximum subarray sum found so far.

We initialize both with nums[0] to correctly handle cases
where all elements are negative.

The answer is the maximum value of currentSum seen during traversal.
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
