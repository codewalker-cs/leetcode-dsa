/*
    Intuition:
    ------------
    We need to choose `n` distinct positive integers such that no
    two chosen numbers add up to `k`, while minimizing their sum.

    The optimal strategy is to first choose the smallest numbers:

        1, 2, 3, ..., m

    where:

        m = min(n, k / 2)

    We can safely choose these numbers because any pair among them
    has a sum less than k.

    After that, if more numbers are needed, we choose numbers starting
    from `k` onwards:

        k, k + 1, k + 2, ...

    These numbers cannot form a pair summing to k with the numbers
    already chosen.

    Instead of calculating the sum one element at a time, we use the
    arithmetic progression sum formula:

        Sum = n * (first + last) / 2

    Approach:
    ----------
    1. Choose the first `m = min(n, k / 2)` numbers.
    2. Calculate their sum:
           1 + 2 + ... + m
    3. Calculate how many additional numbers are required.
    4. Add the sum of the arithmetic progression starting from `k`.
    5. Return the minimum possible sum.

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int minimumSum(int n, int k) {
        //you can use the vector or set to find the element but there is the formula for this too
        int m=min(n,k/2);
        int ans=m*(m+1)/2;
        int rem=n-m;
        ans+=rem*(2*k+rem-1)/2; //s=n(a+l)/2 from AP
        return ans;
    }
};
