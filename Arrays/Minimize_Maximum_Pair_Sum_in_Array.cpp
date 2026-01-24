/*
Intuition:
To minimize the maximum pair sum, we should avoid pairing two large numbers together.
If large numbers are paired together, their sum becomes very large and increases the
maximum pair sum.

By sorting the array and pairing the smallest element with the largest element,
we balance the values in each pair. This prevents any pair from becoming unnecessarily
large and ensures the maximum pair sum is minimized.

Approach:
1. Sort the array in ascending order.
2. Pair the smallest element with the largest, the second smallest with the second largest, and so on.
3. For each pair, compute the sum and keep track of the maximum pair sum.
4. Return the maximum value obtained.

Time Complexity:
- Sorting takes O(n log n)
- Pairing takes O(n)
- Overall complexity is O(n log n)

Space Complexity:
- O(1) extra space (in-place sorting)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int mx = INT_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n / 2; i++) {
            mx = max(mx, nums[i] + nums[n - i - 1]);
        }
        
        return mx;
    }
};
