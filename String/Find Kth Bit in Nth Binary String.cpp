/*
    Problem: Find K-th Bit in N-th Binary String

    Given:
        S1 = "0"
        Si = Si-1 + "1" + reverse(invert(Si-1))

    Observation from YOUR approach:
    --------------------------------
    Instead of constructing the full string like in brute force,
    we observe the recursive structure.

    Let:
        length(n) = 2^n - 1
        mid = 2^(n-1)

    Structure:
        Sn = [ Left (Sn-1) ] + '1' + [ Right (reverse(invert(Sn-1))) ]

    So:

        If k == mid
            → answer = '1'

        If k < mid
            → same as (n-1, k)

        If k > mid
            → mirror position:
                new_k = length - k + 1
              and invert the result

    --------------------------------
    WHY THIS WORKS
    --------------------------------
    The right half is exactly:
        reverse(invert(left half))

    So every position in right half corresponds to
    mirrored position in left half, but inverted.

    --------------------------------
    TIME COMPLEXITY
    --------------------------------
    Each recursive call reduces n by 1.
    Maximum depth = n

    So:
        Time  = O(n)
        Space = O(n)  (recursion stack)

    Much better than brute force O(2^n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    char findKthBit(int n, int k)
    {
        // Base case
        if(n == 1)
            return '0';

        int length = (1 << n) - 1;   // 2^n - 1
        int mid = (length / 2) + 1;  // 2^(n-1)

        // If middle element
        if(k == mid)
            return '1';

        // If in left half
        if(k < mid)
            return findKthBit(n - 1, k);

        // If in right half
        // mirror and invert
        int new_k = length - k + 1;
        char mirrored = findKthBit(n - 1, new_k);

        return (mirrored == '0') ? '1' : '0';
    }
};
