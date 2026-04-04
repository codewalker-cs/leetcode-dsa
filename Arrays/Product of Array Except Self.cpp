/*
 Product of Array Except Self (LeetCode 238)
 ------------------------------------------

 Approach: Prefix + Suffix Product (Without Division)

 ------------------------------------------------------------
 Intuition:
 ------------------------------------------------------------

 For each index i, we need:

     answer[i] = product of all elements except nums[i]

 Instead of division, we compute:

     answer[i] = (product of elements before i) *
                 (product of elements after i)

 ------------------------------------------------------------
 Key Idea:
 ------------------------------------------------------------

 1. First pass (Left → Right):
    - Store prefix product (product of elements before i)

 2. Second pass (Right → Left):
    - Multiply with suffix product (product of elements after i)

 This avoids using extra arrays and keeps space O(1).

 ------------------------------------------------------------
 Example:
 ------------------------------------------------------------

 nums = [1, 2, 3, 4]

 Prefix pass → ans = [1, 1, 2, 6]
 Suffix pass → ans = [24, 12, 8, 6]

 ------------------------------------------------------------
 Complexity:
 ------------------------------------------------------------

 Time  : O(n)
 Space : O(1) (excluding output array)

 ------------------------------------------------------------
 Edge Cases:
 ------------------------------------------------------------

 - Handles zeros naturally (no division used)
 - Works with negative numbers
 - For single element → returns [1]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        
        int pre=1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=pre;
            pre*=nums[i];
        }
        
        int suf=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]*=suf;
            suf*=nums[i];
        }
        return ans;
    }
};
