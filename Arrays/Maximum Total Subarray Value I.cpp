/*
Intuition:
-----------
We need to choose exactly k non-empty subarrays.

The value of a subarray is:
    max(subarray) - min(subarray)

Since:
1. Subarrays can overlap.
2. The same subarray can be chosen multiple times.

We only need to find the maximum possible value of a single subarray and
pick that subarray k times.

The maximum value any subarray can achieve is:
    global_max - global_min

because a subarray containing both the global maximum and global minimum
elements will have exactly this value.

Therefore:
    answer = k * (global_max - global_min)

About 1LL:
----------
1LL is a long long literal.

Without 1LL:
    k * (global_max - global_min)

is computed using int arithmetic first. If the result exceeds the range
of int, overflow occurs before the value is converted to long long.

Example:
    int a = 100000;
    int b = 100000;

    long long x = a * b;      // Overflow
    long long y = 1LL * a * b; // Correct

Using 1LL forces the entire expression to be evaluated in long long,
preventing overflow.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1LL*k*(*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end()));
    }
};
