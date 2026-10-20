/*
    Intuition:
    ------------
    We need to minimize the difference between the maximum and
    minimum elements after changing at most three elements.

    After sorting the array, the smallest values are at the beginning
    and the largest values are at the end.

    Since we can change three elements, we can eliminate the effect
    of the three smallest elements, the three largest elements, or
    some combination of both.

    There are only three meaningful cases to consider:

        1. Change the three largest elements:
           Difference = nums[n - 4] - nums[0]
           Equivalent to nums[n - 1] - nums[2] after considering
           the retained range in the sorted array.

        2. Change the two largest and one smallest element:
           Difference = nums[n - 2] - nums[1]

        3. Change the one largest and two smallest elements:
           Difference = nums[n - 3] - nums[0]

    If the array has at most three elements, we can make all
    elements equal, so the minimum difference is 0.

    Approach:
    ----------
    1. If n <= 3, return 0.
    2. Sort the array.
    3. Calculate the three possible minimum ranges.
    4. Return the smallest range.

    Time Complexity:
    O(n log n)

    Sorting dominates the running time.

    Space Complexity:
    O(log n) auxiliary space for sorting, depending on the
    implementation.
*/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();

        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        return min({nums[n-1]-nums[2],nums[n-2]-nums[1],nums[n-3]-nums[0]});
    }
};
