/*
    Intuition:
    ----------
    For every number, compute its digit range:
        digit range = (largest digit) - (smallest digit)

    While traversing the array:
    1. Find the digit range of the current number.
    2. If this range is greater than the current maximum:
        - Update the maximum range.
        - Reset the answer to the current number.
    3. If this range equals the current maximum:
        - Add the current number to the answer.

    This allows us to determine the required sum in a single traversal.

    ---------------------------------------------------------
    Example:
    nums = [5724, 999, 183, 41]

    5724:
        digits = {5,7,2,4}
        max = 7, min = 2
        range = 5
        maxRange = 5
        sum = 5724

    999:
        range = 0
        Ignore

    183:
        max = 8, min = 1
        range = 7
        New maximum
        sum = 183

    41:
        range = 3
        Ignore

    Answer = 183

    ---------------------------------------------------------
    Time Complexity:
    O(n * d)
    where d is the number of digits in an integer (at most 10).

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int digitRange(int num) {
        if (num == 0) return 0;

        int mn = 9;
        int mx = 0;

        while (num > 0) {
            int digit = num % 10;
            mn = min(mn, digit);
            mx = max(mx, digit);
            num /= 10;
        }

        return mx - mn;
    }

    long long maxDigitRangeSum(vector<int>& nums) {
        int maxRange = -1;
        long long sum = 0;

        for (int num : nums) {
            int range = digitRange(num);

            if (range > maxRange) {
                maxRange = range;
                sum = num;
            } 
            else if (range == maxRange) {
                sum += num;
            }
        }

        return sum;
    }
};
