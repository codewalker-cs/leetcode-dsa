/*
Intuition:
-----------
A number has alternating bits if its binary representation looks like:

    101010...
or  010101...

No two adjacent bits should be equal.

We implement TWO approaches:

--------------------------------------------------
Approach 1: Bit-by-bit traversal (readable)
--------------------------------------------------
We compare adjacent bits from right to left.

Steps:
1. Extract the last bit using n & 1
2. Right shift the number
3. Compare the new last bit with the previous bit
4. If equal → not alternating
5. Continue until all bits are checked

This is easy to understand and interview friendly.

Time:  O(log n)
Space: O(1)

--------------------------------------------------
Approach 2: XOR bit trick (mathematical)
--------------------------------------------------
If bits alternate, then:

    x = n ^ (n >> 1)

becomes a number with all 1s.

Example:
    1010
^   0101
-------
    1111

A number with all 1s satisfies:

    x & (x + 1) == 0

We use unsigned int to avoid signed overflow
when x == INT_MAX.

Time:  O(1)
Space: O(1)
*/

class Solution {
public:

    // ---------------------------
    // Approach 1: Loop method
    // ---------------------------
    bool hasAlternatingBits_loop(int n) {
        int prev = n & 1;
        n >>= 1;

        while (n) {
            int curr = n & 1;

            if (curr == prev)
                return false;

            prev = curr;
            n >>= 1;
        }

        return true;
    }

    // ---------------------------
    // Approach 2: XOR trick
    // ---------------------------
    bool hasAlternatingBits_xor(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }

    bool hasAlternatingBits(int n) {
        return hasAlternatingBits_loop(n);
        // or:
        // return hasAlternatingBits_xor(n);
    }
};
