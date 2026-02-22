/*
    Problem: Binary Gap

    ------------------------------------------------------------
    INTUITION
    ------------------------------------------------------------

    We are given a number n.
    We must find the maximum distance between two consecutive 1s
    in its binary representation.

    Example:
        n = 22
        Binary = 10110
        Positions of 1s = 1, 2, 4 (0-based from right)
        Distances = 1 and 2
        Answer = 2

    ------------------------------------------------------------
    APPROACH 1: Zero Counting Between 1s
    ------------------------------------------------------------

    Idea:
    - Skip bits until we find the first 1.
    - Start counting distance.
    - Every time we see another 1:
        -> Update max distance
        -> Reset count to 1
    - Continue until n becomes 0.

    Time Complexity: O(log n)
    Space Complexity: O(1)

    ------------------------------------------------------------
    APPROACH 2: Track Previous 1 Index (Cleaner)
    ------------------------------------------------------------

    Idea:
    - Traverse each bit.
    - Track index of last seen 1.
    - Whenever we see a new 1:
        -> distance = current_index - previous_index
        -> update max
        -> update previous_index

    This avoids manual zero counting and is cleaner.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {

      
    // ------------------------------------------------------------
    // APPROACH 1: Zero Counting Method
    // ------------------------------------------------------------
      
        // int num=n,b=num&1,count=0,maxcount=0;
        // while(b!=1 && num!=0)
        // {
        //     num>>=1;
        //     b=num&1;
        // }

        // if(b==1) 
        // {
        //     count++;
        // }
        // else
        // {
        //     return 0;
        // }

        // while(num!=0)
        // {
        //     num=num>>1;
        //     int a=num&1;
        //     if(a==1)
        //     {
        //         maxcount=max(count,maxcount);
        //         count=1;
        //     }
        //     else
        //     {
        //         count++;
        //     }
        // }
        // return maxcount;
      
    // ------------------------------------------------------------
    // APPROACH 2: Index Tracking Method (Recommended)
    // ------------------------------------------------------------
      
        int prev=-1,idx=1,maxcount=0;
        while(n!=0)
        {
            if(n&1)
            {
                if(prev!=-1) maxcount=max(maxcount,idx-prev);
                prev=idx;
            }
            n>>=1;
            idx++;
        }
        return maxcount;
    }
};
