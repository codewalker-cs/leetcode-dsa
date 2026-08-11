/*
    Problem:
    Given an array nums where adjacent elements are never equal,
    find any index of a peak element.

    A peak element is an element that is greater than its neighbors.
    The elements outside the array are considered -infinity.

    Intuition:
    We can use binary search.

    Instead of checking whether nums[mid] is directly a peak,
    we look at nums[mid - 1].

    If:
        nums[mid - 1] > nums[mid]

    then we are moving downhill as we go from left to right.
    Therefore, a peak must exist at mid or somewhere to the left.

        r = mid

    Otherwise:
        nums[mid - 1] < nums[mid]

    we are moving uphill.
    Therefore, a peak must exist at mid or somewhere to the right.

        l = mid

    We continue until l == r.
    That index is guaranteed to be a peak.

    Example:
    nums = [1, 2, 3, 1]

    l = 0, r = 3
    mid = 1

    nums[mid - 1] = 1
    nums[mid]     = 2

    1 < 2
    We are going uphill, so:

    l = mid

    Now:
    l = 1, r = 3
    mid = 2

    nums[mid - 1] = 2
    nums[mid]     = 3

    2 < 3
    Again, we are going uphill:

    l = mid

    Now:
    l = 2, r = 3
    mid = 2

    nums[mid - 1] = 2
    nums[mid]     = 3

    l = 2, r = 3
    l == mid, so l does not change.

    We need to avoid an infinite loop by using:
        mid = l + (r - l + 1) / 2

    This chooses the upper middle when l and r are adjacent.

    Time Complexity:
    O(log n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;

        while(l<r)
        {
            int mid=l+((r-l+1)/2);

            if(nums[mid-1]>nums[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid;
            }
        }
        return l;
    }
};
