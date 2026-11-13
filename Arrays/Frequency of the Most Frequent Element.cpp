/*
Intuition:
- We can only increment elements, so it is optimal to make all
  elements in a chosen subarray equal to its largest element.
- After sorting, the rightmost element of a window is its maximum.
- Use a sliding window to find the largest window that can be made
  equal using at most k operations.

Approach:
1. Sort the array.
2. Maintain a sliding window [l, r] and its sum.
3. Treat nums[r] as the target value.
4. Calculate the operations required:
   nums[r] * (r - l + 1) - sum
5. If the required operations exceed k:
   - Remove nums[l] from the sum.
   - Move l forward.
6. Update the maximum window length.
7. Return ans.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) auxiliary space (ignoring sorting implementation).
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int ans=1;
        long long sum=0;

        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];
            while(1LL*nums[r]*(r-l+1)-sum>k)
            {
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
