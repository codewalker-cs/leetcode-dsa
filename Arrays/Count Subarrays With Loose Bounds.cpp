/*
Intuition:
- A valid subarray must contain both minK and maxK.
- Every element must lie within the range [minK, maxK].
- Track the most recent positions of minK, maxK, and the last
  element that was outside the valid range.
- For each index, count how many valid subarrays end there.

Approach:
1. Initialize lastMin, lastMax, and lastInvalid to -1.
2. Traverse the array:
   - If nums[i] is outside [minK, maxK], update lastInvalid.
   - If nums[i] == minK, update lastMin.
   - If nums[i] == maxK, update lastMax.
3. The number of valid subarrays ending at index i is:
   max(0, min(lastMin, lastMax) - lastInvalid).
4. Add this count to the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0,len=0;

        for(int n:nums)
        {
            if(n>=minK && n<=maxK)
            {
                len++;
                ans+=len;
            }
            else
            {
                len=0;
            }
        }
        return ans;
    }
};
