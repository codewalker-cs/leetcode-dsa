/*
Intuition:
-----------
We want to reverse the 32 bits of an integer.

Think of the number as a sequence of bits:
    n = b31 b30 b29 ... b1 b0

We build the result from left to right by repeatedly:
1. Extracting the last bit of n (n & 1)
2. Shifting result left to make space
3. Adding the extracted bit into result
4. Shifting n right to process the next bit

After 32 iterations, all bits are reversed.

Example (4-bit demo):
n = 1101
result builds like:
0001 -> 0010 -> 0101 -> 1011

Time Complexity: O(32) = O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int reverseBits(int n) {
        unsigned int result=0;
        for(int i=0;i<32;i++)
        {
            result<<=1;
            result|=(n&1);
            n>>=1;
        }
        return (int)result;
    }
};
