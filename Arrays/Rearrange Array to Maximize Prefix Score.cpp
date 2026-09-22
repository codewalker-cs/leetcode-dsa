/*
    Intuition:
    ------------
    We want to maximize the number of positive prefix sums.

    To achieve this, we sort the numbers in decreasing order.

    This puts the largest values first, which keeps the running
    prefix sum as large as possible for every prefix.

    After sorting, we calculate the prefix sum:

        pre += nums[i]

    Whenever the prefix sum is strictly positive, this prefix
    contributes to the score.

    If a prefix becomes non-positive, adding smaller elements later
    cannot create a better prefix for an earlier position. Therefore,
    the greedy ordering gives the maximum possible score.

    Approach:
    ----------
    1. Sort the array in decreasing order.
    2. Maintain the running prefix sum.
    3. If the prefix sum is greater than 0, increment the answer.
    4. Return the number of positive prefix sums.

    Time Complexity:
    O(n log n)

    Space Complexity:
    O(log n) auxiliary space for sorting.
*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        long long pre=0,ans=0;
        for(int i=0;i<n;i++)
        {
            pre+=nums[i];
            if(pre>0) ans++;
        }
        return ans;
    }
};
