// Intuition:
// Problem: Count number of 1s in binary representation (Hamming Weight)
//
// We implement TWO approaches:
//
// ------------------------------------------------------------
// Approach 1: Bit-by-bit checking
// ------------------------------------------------------------
// - Check the least significant bit using (n & 1)
// - If it's 1 → increment count
// - Right shift n to process next bit
//
// Important:
// Use (t & 1) == 1, not t & 1 == 1 (operator precedence issue)
//
// Time Complexity: O(32) ≈ O(1)
//
// ------------------------------------------------------------
// Approach 2: Brian Kernighan’s Algorithm
// ------------------------------------------------------------
// - Each operation n = n & (n - 1) removes the rightmost set bit
// - Number of iterations = number of 1s
//
// Example:
// 1101 → 1100 → 1000 → 0000
//
// Time Complexity: O(number of set bits)
//
// ------------------------------------------------------------
// Conclusion:
// Approach 2 is more efficient when number of 1s is small.

class Solution {
public:

    // Approach 1: Bit-by-bit
    int hammingWeight(int n) {
        int t = n, ans = 0;

        while(t > 0)
        {
            if((t & 1) == 1)
            {
                ans++;
            }
            t = t >> 1;
        }

        return ans;
    }

    // Approach 2: Brian Kernighan
    int hammingWeightOptimized(int n) {
        int ans = 0;

        while(n)
        {
            n = n & (n - 1);
            ans++;
        }

        return ans;
    }
};
