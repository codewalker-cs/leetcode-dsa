/*
Intuition:
For every subarray, we need to check whether its bitwise AND
is equal to its minimum element.

Approach:
1. Fix the starting index i.
2. Initialize the bitwise AND and minimum with nums[i].
3. Extend the subarray by moving j forward.
4. Update the bitwise AND and minimum incrementally.
5. If both values are equal, increment the answer.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int me = nums[i];

            ans++;

            for (int j = i + 1; j < n; j++) {
                a &= nums[j];
                me = min(me, nums[j]);

                if (a == me) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
