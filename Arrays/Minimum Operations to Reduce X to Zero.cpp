/*
    Intuition:
    ------------
    We remove elements only from the left or right.

    Therefore, the elements that remain after all removals must form
    one contiguous subarray.

    Suppose the total sum of the array is `total`.

    If we remove elements whose sum is exactly x, then the remaining
    subarray must have:

        remainingSum = total - x

    So the problem becomes:

        Find the longest contiguous subarray with sum = total - x.

    Why the longest?

    If the remaining subarray has length `len`, then the number of
    removed elements is:

        n - len

    Therefore, maximizing the remaining subarray length minimizes
    the number of operations.

    Since nums contains positive integers, we can use a sliding window.

    Approach:
    ----------
    1. Calculate the total sum.
    2. Let target = total - x.
    3. Find the longest subarray with sum = target using two pointers.
    4. Return:
           n - longestLength
    5. If no such subarray exists, return -1.

    Special Case:
    If target == 0, we need to remove the entire array, so the
    answer is n.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n=nums.size();
        long long total=0;
        for(int num:nums)
        {
            total+=num;
        }
        long long target=total-x;
        if (target==0)
        {
            return n;
        }
        int left=0;
        long long sum=0;
        int longest=-1;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];
            while(left<=right&&sum>target)
            {
                sum-=nums[left];
                left++;
            }
            if(sum==target)
            {
                longest=max(longest,right-left+1);
            }
        }
        if(longest==-1)
        {
            return -1;
        }
        return n-longest;
    }
};
