/*
Intuition
---------
The brute force approach checks every possible quadruplet, resulting in O(n^4) time.

Instead, we can:
1. Sort the array.
2. Fix the first two numbers using two loops.
3. Use the Two Pointer technique on the remaining part of the array.
4. Skip duplicate values at every step to avoid repeated quadruplets.

Since the array is sorted:
- If the current sum is smaller than the target, move the left pointer forward.
- If the current sum is larger than the target, move the right pointer backward.
- If the sum matches the target, store the quadruplet and skip duplicates.

Example
-------
nums = [1,0,-1,0,-2,2], target = 0

After sorting:
[-2,-1,0,0,1,2]

i = 0 (-2)

    j = 1 (-1)

        k = 2 (0)
        l = 5 (2)

        sum = -2 + (-1) + 0 + 2 = -1
        Too small -> k++

        k = 3 (0)

        sum = -1
        Too small -> k++

        k = 4 (1)

        sum = 0
        Store {-2,-1,1,2}

    j = 2 (0)

        k = 3 (0)
        l = 5 (2)

        sum = 0
        Store {-2,0,0,2}

Continue similarly for all valid choices.

Algorithm
---------
1. Sort the array.
2. Iterate over the first element (i).
3. Skip duplicate values of i.
4. Iterate over the second element (j).
5. Skip duplicate values of j.
6. Apply two pointers (k and l).
7. Compare the sum with target.
8. Store valid quadruplets.
9. Skip duplicates after every successful match.
10. Return the answer.

Time Complexity
---------------
Sorting: O(n log n)

Outer loop (i): O(n)

Second loop (j): O(n)

Two Pointer traversal: O(n)

Overall:
O(n^3)

Space Complexity
----------------
Ignoring the output list:
O(1)

The answer vector is not counted as extra space.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1]) k++;
                        while(k<l && nums[l]==nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
