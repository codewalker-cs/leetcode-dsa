/*
    Intuition:
    ------------
    We need to find two distinct indices i and j such that:

        nums[i] + nums[j] == target
        nums[i] > nums[j]

    Among all valid pairs, we want the pair with the maximum product:

        nums[i] * nums[j]

    We initialize the maximum product to INT_MIN so that the first
    valid pair can always be selected, even if its product is negative.

    Whenever we find a valid pair:
        1. Calculate its product.
        2. Compare it with the maximum product found so far.
        3. If it is larger, update the answer with indices i and j.

    If no valid pair exists, we return {-1, -1}.

    Approach:
    ----------
    1. Iterate through every possible index i.
    2. Iterate through every possible index j.
    3. Skip the pair if i == j.
    4. Check whether nums[i] > nums[j] and their sum equals target.
    5. Update the answer if the product is maximum.
    6. Return the indices of the best pair.

    Time Complexity:
    O(n²)

    We check every possible pair of indices.

    Space Complexity:
    O(1) auxiliary space.

    The answer vector has a fixed size of 2.
*/

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2,-1);
        int mxp=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(nums[i]>nums[j] && nums[i]+nums[j]==target)
                {
                    if(nums[i]*nums[j]>mxp)
                    {
                        ans[0]=i;
                        ans[1]=j;
                        mxp=nums[i]*nums[j];
                    }
                }
            }
        }
        return ans;
    }
};
