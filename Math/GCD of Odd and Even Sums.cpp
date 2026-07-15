/*
    Intuition:
    ----------
    We need to find the GCD of:
        1. sumOdd  = 1 + 3 + 5 + ... (first n odd numbers)
        2. sumEven = 2 + 4 + 6 + ... (first n even numbers)

    Mathematical Observation:
    -------------------------
    Sum of first n odd numbers:
        sumOdd = n²

    Sum of first n even numbers:
        sumEven = n(n + 1)

    Therefore,
        GCD = gcd(n², n(n + 1))

    Factor out n:
        = n * gcd(n, n + 1)

    Since two consecutive integers are always coprime,
        gcd(n, n + 1) = 1

    Hence,
        Answer = n

    ----------------------------------------------------
    Future Note (Euclidean Algorithm):
    ----------------------------------------------------
    If the sums were not directly simplifiable, we could
    compute their GCD using the Euclidean Algorithm.

    gcd(a, b):
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;

    Example:
        a = 36, b = 24

        36 % 24 = 12
        24 % 12 = 0

        GCD = 12

    Time Complexity:
        O(1)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    // Euclidean Algorithm (useful for future GCD problems)
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {
        // Mathematical simplification:
        // gcd(n², n(n+1)) = n
        return n;

        /*
        Generic approach (not needed for this problem):

        long long sumOdd = 1LL * n * n;
        long long sumEven = 1LL * n * (n + 1);

        return gcd(sumOdd, sumEven);
        */
    }
};
