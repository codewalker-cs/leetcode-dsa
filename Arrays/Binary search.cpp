/*
 * Binary Search (Standard Sorted Array)
 *
 * Intuition:
 * -----------
 * This is the classic Binary Search algorithm which ONLY works on a fully sorted array.
 *
 * Idea:
 * ------
 * At every step:
 * 1. Find the middle element.
 * 2. Compare it with the target:
 *    - If equal → return index
 *    - If mid > target → search LEFT half
 *    - If mid < target → search RIGHT half
 *
 * Why it works:
 * --------------
 * Since the array is sorted, we can safely discard half of the search space
 * after every comparison.
 *
 * IMPORTANT NOTE:
 * ----------------
 * This approach will FAIL for "rotated sorted arrays" (like [4,5,6,7,0,1,2])
 * because the array is not globally sorted.
 *
 * Time Complexity:
 * -----------------
 * O(log n)
 *
 * Space Complexity:
 * ------------------
 * O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return -1;
    }
};
