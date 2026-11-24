/*
Intuition:
We can replace any one of the three integers with the sum of
the other two.

After sorting the values as a <= b <= c, the minimum achievable
range is the minimum of:
1. The original range (c - a).
2. The middle value (b).

Approach:
1. Sort the three integers using swaps.
2. Calculate the original range: c - a.
3. Return the minimum of c - a and b.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int minRange(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);

        return min(c - a, b);
    }
};
