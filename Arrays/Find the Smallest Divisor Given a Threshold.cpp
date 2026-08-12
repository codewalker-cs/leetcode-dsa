/*
    Intuition:
    We need to find the smallest divisor such that:

        sum(ceil(nums[i] / divisor)) <= threshold

    The important observation is that as the divisor increases,
    the sum never increases.

    For example:

        smaller divisor -> larger sum
        larger divisor  -> smaller sum

    Therefore, the answers have this form:

        divisor:  1  2  3  4  5  6  7  ...
        valid:    N  N  N  N  Y  Y  Y  ...

    This monotonic property allows us to use Binary Search.

    Search range:
        l = 1
        r = maximum element in nums

    Why r = maximum element?
    If divisor = maximum element, every nums[i] becomes 1
    after ceiling division, so this is the largest divisor
    we need to consider.

    For each mid, calculate:

        ceil(x / mid)

    Instead of using floating point, we use:

        (x + mid - 1) / mid

    Example:
        x = 7, mid = 3

        ceil(7 / 3)
        = (7 + 3 - 1) / 3
        = 9 / 3
        = 3

    Binary Search:
        If sum > threshold:
            mid is too small.
            We need a larger divisor.

            l = mid + 1

        If sum <= threshold:
            mid works, but there might be a smaller
            valid divisor.

            r = mid

    Example:
        nums = [1, 2, 5, 9]
        threshold = 6

        divisor = 4:
            1 + 1 + 2 + 3 = 7
            Not valid.

        divisor = 5:
            1 + 1 + 1 + 2 = 5
            Valid.

        Therefore the answer is 5.

    Time Complexity:
        O(N log M)

        N = number of elements
        M = maximum element in nums

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            long long sum = 0;

            for (int x : nums) {
                sum += (x + mid - 1) / mid;
            }

            if (sum > threshold) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};
