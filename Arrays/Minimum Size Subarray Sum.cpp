/*
Intuition:

We are asked to find the minimum length subarray whose sum ≥ target.

------------------------------------------------------------
Approach 1 — Brute Force (Restart Window)
------------------------------------------------------------

For every starting index i:
    expand j forward until sum >= target
    record length
    reset and try next i

This works but wastes work because we recompute sums again and again.

Time Complexity: O(n^2)
Space Complexity: O(1)

------------------------------------------------------------
Approach 2 — Sliding Window (Optimal)
------------------------------------------------------------

We maintain a window [l, r] and a running sum.

Expand r → increase sum
While sum >= target:
    update answer
    shrink from left (move l)

Key idea:
Each element is added once and removed once → O(n)

Time Complexity: O(n)
Space Complexity: O(1)

Sliding window never resets.
Pointers only move forward.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int n=nums.size(),l=0,r=1,sum=nums[l],count=1,mincount=INT_MAX;
        // if(sum>target)
        // {
        //     return 1;
        // }
        // while(r<n)
        // {
        //     sum+=nums[r];
        //     count++;
        //     if(sum<target)
        //     {
        //         r++;
        //     }
        //     else
        //     {
        //         l++;
        //         r=l;
        //         mincount=min(count,mincount);
        //         count=0;
        //         sum=0;
        //     }
        // }
        // if(mincount!=INT_MAX) return mincount;
        // return 0;
        int n=nums.size(),l=0,sum=0,mincount=INT_MAX;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                mincount = min(mincount, r - l + 1);
                sum-=nums[l];
                l++;
            }
        }
        if(mincount!=INT_MAX) return mincount;
        return 0;
    }
};
