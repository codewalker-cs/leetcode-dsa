/*
    Intuition:
    We need the longest subsequence whose XOR is non-zero.

    There are only three cases:

    1. If the XOR of the entire array is non-zero:
       We can take the entire array, so the answer is n.

    2. If the XOR of the entire array is zero, but there is at least
       one non-zero element:
       Remove any one non-zero element.

       Since:
           totalXOR = 0

       XOR of the remaining elements becomes:
           0 ^ removedElement = removedElement

       Since the removed element is non-zero, the remaining XOR
       is also non-zero.

       Therefore, the answer is n - 1.

    3. If every element is zero:
       Every possible subsequence will have XOR equal to zero.
       Therefore, no valid subsequence exists and the answer is 0.

    Example:
        nums = [1, 2, 3]

        XOR of entire array:
        1 ^ 2 ^ 3 = 0

        There is a non-zero element.

        Remove 3:
        1 ^ 2 = 3

        XOR is non-zero, so answer = 3 - 1 = 2.

    Time Complexity:
        O(n)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        if (xr != 0) {
            return n;
        }

        if (hasNonZero) {
            return n - 1;
        }

        return 0;
    }
};
