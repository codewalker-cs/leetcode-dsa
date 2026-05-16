/*
Intuition:
-----------
This is a modified Binary Search problem.

For a rotated sorted array:
- If nums[mid] > nums[r], minimum lies in the right half.
- If nums[mid] < nums[r], minimum lies in the left half including mid.
- If nums[mid] == nums[r], we cannot determine the side because duplicates exist.
  So, safely shrink the search space by doing r--.

This guarantees correctness even with duplicates.

Time Complexity:
----------------
Average Case  : O(log n)
Worst Case    : O(n)   (when many duplicates exist)

Space Complexity:
-----------------
O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[0];

        int l=0,r=nums.size()-1;

        while(l<r)
        {
            int mid=l+(r-l)/2;

            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else if(nums[mid]<nums[r])
            {
                r = mid;
            }
            else
            {
                r--;;
            }
        }

        return nums[l];
    }
};
