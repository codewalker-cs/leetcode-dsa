/*
    Intuition:
    ------------
    We need to calculate the sum of the squares of the number of
    distinct elements across every contiguous subarray.

    For each starting index `i`, we consider every possible ending
    index `j`.

    We use a bitset of size 101 to track which values have appeared
    in the current subarray.

        freq.set(nums[j]);

    Setting a bit multiple times does not change it, so each value
    is counted only once.

    The number of distinct elements is obtained using:

        freq.count()

    If the subarray contains `c` distinct elements, its contribution
    to the answer is:

        c * c

    We add this contribution for every subarray.

    Approach:
    ----------
    1. Iterate over every starting index `i`.
    2. Create a fresh bitset to track distinct elements.
    3. Extend the subarray by moving `j` from `i` to `n - 1`.
    4. Mark nums[j] as present.
    5. Count the distinct elements and add their squared count.
    6. Return the total.

    Time Complexity:
    O(n²)

    There are O(n²) subarrays, and bitset operations take constant
    time for this fixed-size bitset.

    Space Complexity:
    O(1)

    The bitset always contains 101 bits.
*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            bitset<101> freq;
            for(int j=i;j<n;j++)
            {
                freq.set(nums[j]);
                int c=freq.count();
                ans+=(c*c);
            }
        }
        return ans;
    }
};
