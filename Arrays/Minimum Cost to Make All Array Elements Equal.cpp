/*
Intuition:
We process consecutive groups of equal elements.

For each group, we calculate the cost using:
    nums[i] * (i + n - j - 1)

where:
- i is the starting index of the group.
- j is the ending index of the group.
- n is the size of the array.

Approach:
1. Iterate through the array and identify consecutive groups
   of equal elements.
2. For each group, find its ending index j.
3. If the group satisfies the conditions:
   - i <= n - 2
   - j >= 1
   calculate its cost.
4. Update the minimum cost.
5. Return the minimum cost.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long ans=LLONG_MAX;

        for(int i=0;i<n;)
        {
            int j=i;
            while(j+1<n && nums[j]==nums[j+1]) j++;
            if(i<=n-2 && j>=1)
            {
                long long cost=1LL*nums[i]*(i+n-j-1);
                ans=min(cost,ans);
            }
            i=j+1;
        }
        return ans;
    }
};
