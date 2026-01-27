/*
LeetCode: Search in Rotated Sorted Array

Intuition:
The array was originally sorted in ascending order but then rotated.
At least one half of the array is always sorted.
Using binary search, we can determine which half is sorted and decide
whether the target lies in that half or the other.

Algorithm:
1. Initialize start = 0 and end = n - 1.
2. While start <= end:
   - Compute mid.
   - If nums[mid] equals target, return mid.
3. Check which half is sorted:
   - If left half is sorted:
     * If target lies within left half, move end.
     * Otherwise, move start.
   - Else right half is sorted:
     * If target lies within right half, move start.
     * Otherwise, move end.
4. If target is not found, return -1.

Time Complexity:
O(log n)
Binary search is applied by reducing the search space by half each time.

Space Complexity:
O(1)
Only constant extra space is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            if(nums[mid]==target)
            {
                return mid;
            }
            
            if(nums[start] <= nums[mid])
            { 
                if(nums[start]<=target && nums[mid]>target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[end])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
