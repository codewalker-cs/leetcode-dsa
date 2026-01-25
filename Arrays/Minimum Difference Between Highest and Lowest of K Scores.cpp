/*
LeetCode 1984: Minimum Difference Between Highest and Lowest of K Scores

Intuition:
----------
We need to select any k students such that the difference between the
highest and lowest score in that selected group is minimized.

Key Observation:
----------------
If the array is sorted, then the best group of k students will always be
formed by k consecutive elements in the sorted array.

Reason:
- Choosing non-consecutive elements would only increase the gap between
  the minimum and maximum values.
- Therefore, we only need to check all windows of size k.

Approach:
---------
1. If k == 1, the difference is 0 (max == min).
2. Sort the array.
3. Slide a window of size k over the sorted array.
4. For each window, compute:
      difference = nums[i]-nums[i-k+1]
5. Return the minimum difference found.

Time Complexity:
----------------
O(n log n) due to sorting.

Space Complexity:
-----------------
O(1) extra space (ignoring sort stack).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mi=INT_MAX,diff;
        for(int i=nums.size()-1;i>=k-1;i--)
        {
            diff=nums[i]-nums[i-k+1];
            mi=min(mi,diff);
        }
        return mi;
    }
};
