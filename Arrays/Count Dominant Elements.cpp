/*
Intuition:
An element is dominant if it is greater than or equal to the
average of its adjacent elements.

For the first and last elements, only one adjacent element exists.

Approach:
1. Handle the single-element array separately.
2. For the first element, compare it with the second element.
3. For the last element, compare it with the previous element.
4. For every middle element, check:
      2 * nums[i] >= nums[i - 1] + nums[i + 1]
5. Increment the answer whenever the condition is satisfied.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(nums[i]>=nums[i+1]) ans++;
                continue;
            }

            if(i==n-1)
            {
                if(nums[i]>=nums[i-1]) ans++;
                continue;
            }
            if(2LL * nums[i]>= nums[i-1]+nums[i+1]) ans++;
        }
        return ans;
    }
};
