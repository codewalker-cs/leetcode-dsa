/*
    Intuition:
    ------------
    This is a modified Binary Search on a rotated sorted array.

    In a normal rotated sorted array, at least one of the two halves
    around mid is sorted.

    Example:
        [4, 5, 6, 7, 0, 1, 2]
         l     mid        r

    Here, the left half [4, 5, 6, 7] is sorted.

    We can check whether the target lies inside that sorted half.
    If it does, search there; otherwise, search the other half.

    However, this problem allows DUPLICATES.

    Example:
        [1, 1, 1, 0, 1]

    If:
        nums[l] == nums[mid] == nums[r]

    we cannot determine which half is sorted.

    In that case, we remove the duplicate values from both ends:
        l++;
        r--;

    Then continue Binary Search.


    Step-by-step example:
    ---------------------

    nums = [2, 5, 6, 0, 0, 1, 2]
    target = 0

    l = 0, r = 6
    mid = 3

    nums[mid] == target
    Therefore, return true.


    Another example:

    nums = [1, 0, 1, 1, 1]
    target = 0

    l = 0, mid = 2, r = 4

    nums[l] == nums[mid] == nums[r]
    Therefore, we cannot determine which half is sorted.

    We do:
        l++;
        r--;

    Now we continue searching the smaller range.


    Time Complexity:
    ----------------
    Average Case: O(log n)

    Worst Case: O(n)

    The worst case happens because duplicates can force us to
    remove elements one by one when we cannot determine the
    sorted half.


    Space Complexity:
    -----------------
    O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();

        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]==target) return true;
        // }
        // return false;

        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(nums[mid]==target) return true;

            if(nums[l]==nums[mid] && nums[r]==nums[mid])
            {
                l++;
                r--;
            }
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<nums[mid])
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
                if(nums[mid]<target && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};
