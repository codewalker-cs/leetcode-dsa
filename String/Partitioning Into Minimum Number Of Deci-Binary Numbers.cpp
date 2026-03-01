/*
    Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers

    ------------------------------------------------------------------
    INTUITION
    ------------------------------------------------------------------

    A deci-binary number is a number whose digits consist only of 0 or 1
    and it has no leading zeros.

    We are given a decimal number as a string. We must determine the
    minimum number of positive deci-binary numbers whose sum equals n.

    ------------------------------------------------------------------
    KEY OBSERVATION
    ------------------------------------------------------------------

    Each deci-binary number can contribute at most 1 to any digit position.

    Suppose a digit in n is:
        - 3 → we need at least 3 deci-binary numbers.
        - 7 → we need at least 7 deci-binary numbers.

    Why?

    Because each deci-binary number can only add 1 at that position.
    So if a column has digit d, we need at least d layers of 1s.

    Therefore, the minimum number of deci-binary numbers required
    is equal to the maximum digit present in the string.

    Answer = Maximum digit in n

    ------------------------------------------------------------------
    OPTIMIZATION
    ------------------------------------------------------------------

    Since digits range from 0 to 9,
    if we encounter '9', we can immediately return 9,
    as no digit can be larger.

    ------------------------------------------------------------------
    COMPLEXITY
    ------------------------------------------------------------------

    Time Complexity  : O(n)
    Space Complexity : O(1)

    We must scan the string once, which is optimal.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;

        for (char c : n) {
            if (c == '9')
                return 9;  // Early exit (maximum possible digit)

            maxDigit = max(maxDigit, c - '0');
        }

        return maxDigit;
    }
};
