/*
Intuition:
-----------
We are given an array nums and asked to compute the maximum value of the rotation function:
F(k) = sum of i * B_k[i], where B_k is the array after k rotations.

A brute force approach would rotate the array every time and recompute F(k),
which costs O(n^2). This is too slow.

Key Optimization:
----------------
We observe a recurrence relation between consecutive rotations:

F(k) = F(k-1) + total_sum - n * nums[n - k]

Why?
- When we rotate the array, every element shifts one position to the right → contributes +total_sum
- The last element moves to index 0 → we subtract n * that element

So instead of recomputing from scratch, we update in O(1).

Steps:
------
1. Compute:
   - total_sum = sum of all elements
   - F(0) = sum of nums[i] * i

2. Use recurrence to compute F(1), F(2), ..., F(n-1)

3. Track maximum value

Important:
-----------
Use long long to avoid overflow because nums[i] * i can exceed int range.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(),sum=0,f=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            f+=(nums[i]*i);
        }

        int ans=f;

        for(int i=1;i<n;i++)
        {
            int diff=sum-(n*nums[n-i]);
            f=f+diff;
            ans=max(ans,f);
        }
        return ans;
    }
};
