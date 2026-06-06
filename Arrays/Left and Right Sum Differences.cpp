/*
Intuition:
For every index i, we need:
- leftSum[i]  = sum of all elements to the left of i
- rightSum[i] = sum of all elements to the right of i

We precompute both arrays:
- Build leftSum from left to right.
- Build rightSum from right to left.

Then:
answer[i] = abs(leftSum[i] - rightSum[i])

Example:
nums = [10, 4, 8, 3]

leftSum  = [0, 10, 14, 22]
rightSum = [15, 11, 3, 0]

answer = [15, 1, 11, 22]

Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
Intuition:
Instead of storing separate left and right sum arrays,
maintain them while traversing the array.

Initially:
- rightSum = total sum of all elements.
- leftSum = 0.

At index i:
1. Remove nums[i] from rightSum.
   Now rightSum represents the sum of elements strictly
   to the right of i.

2. Compute:
   abs(leftSum - rightSum)

3. Add nums[i] to leftSum.
   Now leftSum represents the sum of elements up to i
   for the next iteration.

This avoids storing extra arrays.

Time Complexity: O(n)
Space Complexity: O(1) (excluding the output array)
*/

// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ls(n,0),rs(n,0);

//         for(int i=1;i<n;i++)
//         {
//             ls[i]=ls[i-1]+nums[i-1];
//             rs[n-i-1]=rs[n-i]+nums[n-i];
//         }

//         vector<int> ans(n,0);
//         for(int i=0;i<n;i++)
//         {
//             ans[i]=abs(ls[i]-rs[i]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();

        int rs=0;
        for(int x : nums) rs+=x;

        int ls=0;
        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            rs-=nums[i];
            ans[i]=abs(ls-rs);
            ls+=nums[i];
        }

        return ans;
    }
};
