/*
    Problem: 15. 3Sum
    Difficulty: Medium

    Intuition:
    - Sort the array so that we can efficiently use the two-pointer technique.
    - Fix one element at a time and search for the remaining two elements
      whose sum equals the negative of the fixed element.
    - Since the array is sorted:
        * If the current sum is too small, move the left pointer right.
        * If the current sum is too large, move the right pointer left.
        * If the sum is exactly zero, store the triplet and move both pointers.
    - Skip duplicate values for the fixed element and both pointers to avoid
      generating duplicate triplets.

    Time Complexity: O(n²)
    Space Complexity: O(1) excluding the output array.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                long long sum=(long long)nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(sum>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};
