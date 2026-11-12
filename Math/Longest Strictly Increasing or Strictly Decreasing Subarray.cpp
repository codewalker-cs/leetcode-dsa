/*
Intuition:
- A monotonic subarray is either strictly increasing or strictly decreasing.
- Maintain two counters:
  - inc: Length of the current strictly increasing subarray.
  - dec: Length of the current strictly decreasing subarray.
- If two consecutive elements are equal, both sequences break.

Approach:
1. Initialize inc, dec, and ans to 1.
2. Traverse the array starting from index 1.
3. If nums[i] > nums[i - 1]:
   - Increment inc.
   - Reset dec to 1.
4. If nums[i] < nums[i - 1]:
   - Increment dec.
   - Reset inc to 1.
5. If both elements are equal, reset both counters to 1.
6. Update ans with the maximum of inc and dec.
7. Return ans.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int inc = 1, dec = 1;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};
