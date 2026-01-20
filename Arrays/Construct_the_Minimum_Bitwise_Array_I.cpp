/*This was IMP Learning
===============================================================================
Problem:
Given an array nums of prime integers.
For each nums[i], find the minimum integer x such that:
    x | (x + 1) == nums[i]

If no such x exists, return -1 for that index.

===============================================================================
Intuition & Bitwise Explanation:

1) Even Case (Immediate Rejection)
---------------------------------
For any integer x:
    x | (x + 1)
is ALWAYS odd.

Reason:
- Adding 1 flips the rightmost 0 to 1
- Bitwise OR ensures the least significant bit becomes 1

Therefore:
- If nums[i] is even, it is impossible to form it
- So the answer is -1

===============================================================================
2) Odd Case (Valid Numbers Only)
--------------------------------
Only odd numbers can be expressed as x | (x + 1).

Binary Behavior of (x + 1):
- All trailing 1s become 0
- The first 0 to the left becomes 1

Example:
    x     = 1000111
    x + 1 = 1001000
    OR    = 1001111

This creates a number with a suffix of consecutive 1s.

===============================================================================
3) Key Observation
------------------
Given:
    n = x | (x + 1)

- n and x differ at exactly ONE bit
- That bit is the LEFTMOST '1' in the trailing ones of n

So:
- To recover the minimum x from n,
  we must FLIP the leftmost trailing one in n.

===============================================================================
4) How to Find That Bit
----------------------
There is no direct way to find the rightmost zero in n,
so we invert the bits.

Let:
    q = ~n

Now:
- Zeros in n become ones in q
- We can use the classic trick to find the rightmost set bit

Lowest set bit trick:
    q & (-q)

Using two's complement:
    -(~n) = n + 1

So the expression becomes:
    (n + 1) & (~n)

This isolates the RIGHTMOST ZERO BIT of n.

===============================================================================
5) Leftmost Trailing One
-----------------------
The rightmost zero bit corresponds to the bit just BEFORE
the trailing ones.

Shifting right by 1 gives:
    z = ((n + 1) & (~n)) >> 1

This z represents the leftmost trailing one in n.

===============================================================================
6) Constructing the Minimum x
-----------------------------
To remove that bit from n:
    x = n & (~z)

This produces the MINIMUM x such that:
    x | (x + 1) == n
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if ((n & 1) == 0)
                continue;
            int z = ((n + 1) & (~n)) >> 1;
            ans[i] = n & (~z);
        }

        return ans;
    }
};
//         My original solution
//=================================================
//         vector<int> ans(nums.size(),-1);
//         for(int i=0;i<nums.size();i++)
//         {
//             int j=nums[i];
//             if(j%2==0)
//             {
//                 continue;
//             }
//             while(j>0)
//             {
//                 if((j|(j+1))==nums[i])
//                 {
//                     if(ans[i]>j||ans[i]==-1)
//                     {
//                         ans[i]=j;
//                     }
//                 }
//                 j--;
//             }
//         }
//         return ans;
//     }
// };
