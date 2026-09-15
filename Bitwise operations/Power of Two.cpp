/*
    Intuition:
    ------------
    A positive number is a power of two if and only if its binary
    representation contains exactly one set bit (1).

    For example:

        1  = 0001
        2  = 0010
        4  = 0100
        8  = 1000

    For any power of two, subtracting 1 changes that single set bit
    into 0 and turns all bits after it into 1.

        8     = 1000
        8 - 1 = 0111

    Therefore:

        n & (n - 1) = 0

    We also need `n > 0` because 0 is not a power of two.

    Important:
    ----------
    Parentheses are necessary around `(n & (n - 1))`.

    Without them, the expression:

        n & (n - 1) == 0

    is parsed incorrectly because `==` has higher precedence than
    bitwise `&`.

    Approach:
    ----------
    1. Check that n is positive.
    2. Check whether n has exactly one set bit using:
           (n & (n - 1)) == 0
    3. Return the result.

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
    }
};
