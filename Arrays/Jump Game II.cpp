/*
Intuition
----------
We treat the array like BFS levels (range expansion).

- currentEnd:
    Represents the farthest index reachable using the current number of jumps.

- maxReach:
    Stores the farthest index we can reach while exploring the current range.

Whenever we reach currentEnd, it means:
we have explored every position possible with the current jump,
so we must take another jump.

Greedy Observation
-------------------
Instead of deciding the exact next index to jump to,
we only care about the farthest reachable position from the current range.

Time Complexity
----------------
O(n)

Space Complexity
-----------------
O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0,ce=0,mr=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            mr=max(i+nums[i],mr);
            if(i==ce)
            {
                j++;
                ce=mr;
            }
        }
        return j;
    }
};
