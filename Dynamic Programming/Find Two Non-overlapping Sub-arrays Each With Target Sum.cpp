/*
Intuition:
- Use a sliding window to find every subarray whose sum is exactly k.
- dp[i] stores the minimum length of a valid subarray completely inside
  the first i elements.
- When arr[j...i] has sum k, combine it with the best valid subarray
  ending before j.
- Update dp so that it always stores the minimum valid length seen so far.

Walkthrough:
- sum maintains the current window sum.
- j is the left boundary of the sliding window.
- If sum > k, move j forward until sum <= k.
- If sum == k, current subarray length is i-j+1.
- dp[i] represents the best previous non-overlapping subarray.
- Therefore:
      current length + dp[i]
  gives the answer for two non-overlapping subarrays.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int k) {
        int n = arr.size();
        int res = n + 1;
        int sum = 0;
        int j = 0;

        vector<int> dp(n + 1, n);

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            while (sum > k) {
                sum -= arr[j++];
            }

            dp[i + 1] = dp[i];

            if (sum == k) {
                res = min(res, i - j + 1 + dp[i]);

                dp[i + 1] = min(dp[i], i - j + 1);
            }
        }

        return res == n + 1 ? -1 : res;
    }
};
