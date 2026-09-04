/*
    Intuition:
    ------------
    For every index i, we need to compare the maximum value in the
    prefix [0 ... i] with the minimum value in the suffix [i ... n-1].

    We precompute both values:

        mx[i] = maximum element from index 0 to i
        mi[i] = minimum element from index i to n-1

    Then for each index i:

        mx[i] - mi[i]

    tells us the difference between the largest value on the left
    and the smallest value on the right.

    The first index where this difference is less than k is the
    required stable index.

    Approach:
    ----------
    1. Build the prefix maximum array `mx`.
    2. Build the suffix minimum array `mi`.
    3. Traverse from left to right.
    4. Return the first index where:
           mx[i] - mi[i] < k
    5. If no such index exists, return -1.

    Time Complexity:
    O(n)

    Space Complexity:
    O(n)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mi(n,0),mx(n);
        mx[0]=nums[0];
        mi[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            mx[i]=max(mx[i-1],nums[i]);
            mi[n-1-i]=min(mi[n-i],nums[n-1-i]);
        }

        for(int i=0;i<n;i++)
        {
            if(mx[i]-mi[i]<=k) return i;
        }
        return -1;
    }
};
