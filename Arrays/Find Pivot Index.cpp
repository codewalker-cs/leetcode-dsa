/*
========================================
        Pivot Index (LeetCode)
========================================

Intuition:
-----------
We need to find an index such that:
    sum of elements to the left == sum of elements to the right

Brute Force:
-------------
For every index:
    - Calculate left sum (O(n))
    - Calculate right sum (O(n))
Total complexity = O(n^2)

Optimized Approach:
-------------------
Instead of recalculating sums repeatedly:
1. Compute total sum of array (rsum initially).
2. Traverse the array:
    - At each index:
        a. Subtract current element from rsum → now rsum = right sum
        b. Compare lsum and rsum
        c. If equal → return index
        d. Add current element to lsum → update left sum

Key Observation:
----------------
At any index i:
    Left sum = sum of elements before i
    Right sum = total sum - (left sum + nums[i])

Invariant:
-----------
Before checking:
    rsum = sum of elements to the right
    lsum = sum of elements to the left

Time Complexity:
----------------
O(n) → single pass

Space Complexity:
-----------------
O(1) → no extra space used

Edge Cases:
------------
- Single element → always pivot (index 0)
- No valid pivot → return -1
- Negative numbers → handled naturally

========================================
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum=0,lsum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            rsum+=nums[i];
        }

        for(int i=0;i<n;i++)
        {
            rsum-=nums[i];
            if(lsum==rsum)
            {
                return i;
            }
            else
            {
                lsum+=nums[i];
            }
        }
        return -1;
    }
};
