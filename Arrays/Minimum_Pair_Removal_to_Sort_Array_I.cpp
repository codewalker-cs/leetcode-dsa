/*
==========================================================
Problem: Minimum Pair Removal to Make Array Non-Decreasing
==========================================================

Intuition:
----------
We are allowed to repeatedly merge only ONE type of pair:
the adjacent pair with the minimum sum (leftmost in case
of ties). Since this choice is forced by the problem,
a greedy simulation is the correct approach.

Merging the smallest adjacent sum minimizes the local
increase and helps the array move towards a non-decreasing
state. Each merge reduces the array size by one, guaranteeing
termination.

----------------------------------------------------------

Algorithm:
----------
1. If the array is already non-decreasing, return 0.
2. While the array is not non-decreasing:
   a) Compute sums of all adjacent pairs.
   b) Find the minimum adjacent sum (leftmost).
   c) Replace the pair with their sum.
   d) Increment the operation count.
3. Return the operation count.

----------------------------------------------------------

Correctness Justification:
--------------------------
At every step, the problem enforces a greedy choice:
we MUST merge the adjacent pair with the minimum sum.
No alternative choice is allowed, hence simulating this
process produces the minimum number of operations.

----------------------------------------------------------

Complexity Analysis:
--------------------
Let n be the initial size of the array.
- Time Complexity: O(n^2)
  (Each merge scans the array and reduces its size by one)
- Space Complexity: O(n)
  (Temporary array to store adjacent sums)

----------------------------------------------------------
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        int count=0;
        while(nums.size()>1 && !is_sorted(nums.begin(), nums.end()))
        {
            vector<int> temp(nums.size()-1);
            for(int i=0;i<nums.size()-1;i++)
            {
                temp[i]=nums[i]+nums[i+1];
            }
            auto it = min_element(temp.begin(), temp.end());
            int id = it - temp.begin();
            nums[id]=temp[id];
            nums.erase(nums.begin()+id+1);
            count++;
        }
        return count;
    }
};
