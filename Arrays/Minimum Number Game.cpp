/*
Intuition:
----------
The game repeatedly picks the two smallest remaining numbers,
then places them in reversed order in the result.

Instead of simulating removal each time (which is slow),
we notice a pattern:

If we sort the array first:
nums = [a, b, c, d, e, f]  (sorted)

The two smallest are always adjacent:
(a, b), (c, d), (e, f)

The game simply swaps each adjacent pair:
→ (b, a), (d, c), (f, e)

So the optimal strategy is:
1. Sort the array
2. Swap every pair of neighbors

This reduces the problem to a simple O(n log n) sorting + O(n) swapping.

Time Complexity: O(n log n)
Space Complexity: O(1) extra (in-place)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int> arr;
        for(int i=0;i<nums.size();i+=2)
        {
            // arr.push_back(nums[i+1]);
            // arr.push_back(nums[i]);
            swap(nums[i],nums[i+1]);
        }
        // return arr;
        return nums;
    }
};
