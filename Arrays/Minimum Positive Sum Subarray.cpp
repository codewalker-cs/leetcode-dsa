/*
Intuition:
We need to find the minimum positive sum among all subarrays
whose lengths lie between l and r.

Approach:
1. Build a prefix sum array where ps[i] stores the sum of
   elements from index 0 to i.
2. Iterate through every starting index i.
3. Try all possible subarray lengths k from l to r.
4. Calculate the subarray sum using prefix sums:
      sum = ps[i + k - 1] - ps[i - 1]
5. If the sum is positive, update the answer.

Time Complexity: O(n * (r - l + 1))
Space Complexity: O(n)
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX,n=nums.size();
        vector<int> ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            for(int k=l;k<=r;k++)
            {
                if(i+k>n) break;
                int s=ps[i+k-1];

                if(i>0) s-=ps[i-1];
                if(s>0) ans=min(ans,s);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
