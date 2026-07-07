/*
    ==========================================================
    2810. Concatenate Non-Zero Digits and Multiply by Sum I
    ==========================================================

    Problem:
    --------
    Given an integer n:
    1. Form a new integer x by concatenating all the non-zero
       digits of n in their original order.
    2. Compute the sum of the digits in x.
    3. Return x * sum.

    If n contains only zeros, then x = 0.

    ----------------------------------------------------------
    Intuition
    ----------------------------------------------------------
    - Traverse every digit of n.
    - Ignore all '0' digits.
    - While traversing:
        * Build the new number x.
        * Keep track of the sum of its digits.
    - Finally return x * sum.

    Example:
    --------
    n = 1020304

    Non-zero digits = 1, 2, 3, 4

    x   = 1234
    sum = 1 + 2 + 3 + 4 = 10

    Answer = 1234 * 10 = 12340

    ----------------------------------------------------------
    Algorithm
    ----------------------------------------------------------
    1. Convert n into a string.
    2. Initialize:
           x = 0
           sum = 0
    3. Traverse every character.
        - Skip '0'.
        - Append the digit to x.
        - Add the digit to sum.
    4. Return x * sum.

    ----------------------------------------------------------
    Complexity Analysis
    ----------------------------------------------------------
    Time Complexity : O(d)
        d = number of digits in n.

    Space Complexity : O(1)
        (Ignoring the string created by to_string()).

*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long x=0;
        int sum=0;
        for(char &c : s)
        {
            if(c!='0')
            {
                x=(x*10)+(c-'0');
                sum+=(c-'0');
            }
        }
        return sum*x;
    }
};
