/*
 * Pow(x, n) — Binary Exponentiation (Fast Power)
 *
 * Intuition:
 * Instead of multiplying x repeatedly (O(n)),
 * we use binary exponentiation to reduce time to O(log n).
 *
 * Idea:
 * - If n is even:
 *     x^n = (x * x)^(n / 2)
 *
 * - If n is odd:
 *     x^n = x * (x * x)^((n - 1) / 2)
 *
 * We repeatedly:
 * - square the base (x = x * x)
 * - reduce the exponent (n = n / 2)
 *
 * Edge Cases:
 * - n can be negative:
 *     x^(-n) = 1 / x^n
 *
 * - Use long long for n to avoid overflow when n = INT_MIN
 *
 * Time Complexity:
 * O(log n)
 *
 * Space Complexity:
 * O(1)
 */

class Solution {
public:
    double myPow(double x, int n) {
        long long power=n;
        double result=1;
        if(n<0)
        {
            power=-power;
            x=(1/x);
        }

        while(power>0)
        {
            if(power%2==1)
            {
                result*=x;
            }

            x*=x;
            power/=2;
        }

        return result;
    }
};
