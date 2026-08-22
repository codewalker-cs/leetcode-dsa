/*
    Intuition:
    The number is divisible by the sum of its digits plus
    the product of its digits.

    Approach:
    1. Extract every digit of n.
    2. Add each digit to `sum`.
    3. Multiply each digit into `product`.
    4. Check whether n is divisible by (sum + product).

    Example:
    n = 123

    Digits: 1, 2, 3
    Sum = 1 + 2 + 3 = 6
    Product = 1 * 2 * 3 = 6
    sum + product = 12

    Since 123 % 12 != 0, the answer is false.

    Time Complexity:
    O(log n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,p=1,t=n;
        while(t>0)
        {
            s+=t%10;
            p*=t%10;
            t=t/10;
        }
        return !(n%(s+p));
    }
};
