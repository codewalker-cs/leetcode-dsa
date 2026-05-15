/*
Intuition:
-----------
In a rotated sorted array:
- If nums[mid] > nums[right],
  minimum lies in the right half.
- Otherwise,
  minimum lies in the left half including mid.

We shrink the search space using Binary Search.

Time Complexity  : O(log n)
Space Complexity : O(1)
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
            else
            {
                r=mid;
            }
        }

        return nums[l];
    }
};
