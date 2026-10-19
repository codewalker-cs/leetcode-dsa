/*
    Intuition:
    ------------
    We need to find all indices where `target` would appear after
    sorting the array in non-decreasing order.

    Instead of sorting the array, we can calculate the required
    indices directly.

    We maintain two counts:

        small = number of elements smaller than target
        freq  = number of occurrences of target

    After sorting, all elements smaller than target appear before
    every occurrence of target.

    Therefore, the first occurrence of target will be at index:

        small

    Since target appears `freq` times, its indices will be:

        small, small + 1, ..., small + freq - 1

    If target does not exist in the array, we return an empty vector.

    Approach:
    ----------
    1. Count elements smaller than target.
    2. Count occurrences of target.
    3. If target does not exist, return an empty vector.
    4. Generate `freq` consecutive indices starting from `small`.
    5. Return the answer.

    Time Complexity:
    O(n)

    We traverse the array once and generate the answer in O(freq).

    Space Complexity:
    O(freq)

    The answer vector stores all target indices.
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0,freq=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<target) small++;
            if(nums[i]==target) freq++;
        }
        if(freq==0) return {};
        vector<int> ans(freq,0);
        for(int i=0;i<freq;i++)
        {
            ans[i]=small+i;
        }
        return ans;
    }
};
