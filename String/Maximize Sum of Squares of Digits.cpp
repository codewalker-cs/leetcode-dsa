/*
    Intuition:
    ------------
    We need to construct a `num`-digit positive integer whose digit
    sum is exactly `sum`, while maximizing the sum of the squares
    of its digits.

    The key observation is that larger digits contribute more to
    the sum of squares.

    For example:
        9² + 1² = 82
        5² + 5² = 50

    Therefore, we should maximize each digit by placing as many 9s
    as possible from left to right.

    If the remaining sum is less than 9, we place that value as the
    next digit and fill the remaining positions with zeros.

    If `sum > 9 * num`, the required digit sum is impossible because
    each digit can be at most 9.

    If `sum == 0`, no positive integer can satisfy the requirements,
    so we return an empty string.

    Approach:
    ----------
    1. If sum > 9 * num or sum == 0, return "".
    2. Build the answer from left to right.
    3. Place 9 whenever the remaining sum is at least 9.
    4. Otherwise, place the remaining sum as a digit and set the
       remaining sum to zero.
    5. Continue until the number has exactly `num` digits.

    Time Complexity:
    O(num)

    Space Complexity:
    O(num)

    The answer string stores `num` digits.
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num || sum==0) return "";

        string ans="";

        for(int i=0;i<num;i++)
        {
            if(sum>=9)
            {
                ans+='9';
                sum-=9;
            }
            else
            {
                ans+=char('0'+sum);
                sum=0;
            }
        }
        return ans;
    }
};
