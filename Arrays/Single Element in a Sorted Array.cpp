/*
Single Element in a Sorted Array (LeetCode 540)
------------------------------------------------

Approach: Binary Search (Index Parity Logic)

------------------------------------------------------------
Intuition:
------------------------------------------------------------

In a sorted array where every element appears twice except one,
the pairs follow a pattern:

Before the single element:
    first occurrence at even index
    second occurrence at odd index

After the single element:
    first occurrence at odd index
    second occurrence at even index

We use this pattern to eliminate half of the array using binary search.

------------------------------------------------------------
Logic:
------------------------------------------------------------

1. Handle edge cases:
   - If array size is 1 → return that element
   - If single element is at start or end

2. For mid:
   - If nums[mid] is different from both neighbors → answer found

3. Use index parity:
   - If mid is even:
        - If nums[mid] == nums[mid-1], we are on the RIGHT side → move left
        - Else → move right
   - If mid is odd:
        - If nums[mid] == nums[mid-1], we are on the LEFT side → move right
        - Else → move left

------------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,n=nums.size();
        if(n==1) return nums[0];
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(mid==0 && nums[0]!=nums[1]) return nums[0];
            if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[n-1];

            if(nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid])
            {
                return nums[mid];
            }
            
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid-1])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return 0;
    }
};
