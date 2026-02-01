/*
Intuition:
-----------
We must divide the array into 3 contiguous subarrays.
The cost of each subarray is its first element.

No matter how we split:
- The first subarray always starts at index 0 → nums[0] is forced.
- We only need to choose 2 additional starting points i and j
  where 1 <= i < j < n.

So the problem reduces to:
    nums[0] + smallest two values from indices [1 … n-1]

We scan once and track the two minimum elements after index 0.

Greedy idea:
- min1 = smallest seen so far
- min2 = second smallest seen so far
When a new number comes:
    if it’s smaller than min1 → shift values
    else if smaller than min2 → update min2

This guarantees we always keep the best two candidates.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            int k = nums[i];

            if (k < min1) {
                min2 = min1;
                min1 = k;
            }
            else if (k < min2) {
                min2 = k;
            }
        }

        return nums[0] + min1 + min2;
    }
};
