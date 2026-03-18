/*
========================================
Problem: Single Number II
========================================

Intuition:

- Every element appears 3 times except one.
- We need to find that single element using:
    O(N) time
    O(1) space

----------------------------------------
Core Idea (Bit State Tracking):

We use two variables:

1. ones -> stores bits that appeared once
2. twos -> stores bits that appeared twice

When a bit appears the third time,
it is removed from both.

----------------------------------------
State Transition (per bit):

0 -> ones -> twos -> removed (back to 0)

----------------------------------------
Logic:

ones = (ones ^ x) & ~twos
twos = (twos ^ x) & ~ones

- XOR (^) toggles bits
- AND with ~ removes bits already counted

----------------------------------------
Why it works:

- Bits appearing three times cancel out
- Only the unique number remains in 'ones'

----------------------------------------
Time Complexity: O(N)
Space Complexity: O(1)

========================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> freq;
        // int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     freq[nums[i]]++;
        // }

        // for(int i=0;i<n;i++)
        // {
        //     if(freq[nums[i]]%3!=0)
        //     {
        //         return nums[i];
        //     }
        // }
        // return 0;

        int ones=0, twos=0;

        for(int x:nums)
        {
            ones=(ones^x)&~twos;
            twos=(twos^x)&~ones;
        }

        return ones;
    }
};
