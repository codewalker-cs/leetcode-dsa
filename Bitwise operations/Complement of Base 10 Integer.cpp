/*
    Intuition
    ---------
    The bitwise complement of a number means flipping all bits in its binary
    representation (0 -> 1 and 1 -> 0).

    Example:
        n = 5
        binary representation = 101

        complement = 010
        decimal value = 2

    Idea
    ----
    If we directly use the NOT (~) operator, it flips all 32 bits of an integer,
    which gives unwanted leading 1s. Therefore we only want to flip the bits
    that actually belong to the number.

    Steps:
    1. Count how many bits are present in n.
    2. Create a mask consisting of all 1s of that length.
       Example:
           n = 5 -> 101 (3 bits)
           mask = 111
    3. XOR the number with the mask.
       XOR with 1 flips the bit.

       Example:
            101
          ^ 111
          -----
            010  -> 2

    Special Case
    ------------
    If n = 0
    binary = 0
    complement = 1

    Time Complexity:  O(log n)   (number of bits)
    Space Complexity: O(1)
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        
        int temp=n,n1=0;

        while(temp!=0)
        {
            temp>>=1;
            n1=(n1<<1)|1;
        }
        return n^n1;
    }
};
