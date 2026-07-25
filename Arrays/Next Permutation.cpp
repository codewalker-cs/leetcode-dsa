/*
    Intuition:
    -----------
    To generate the next lexicographically greater permutation, we need to make
    the smallest possible change to the current arrangement.

    Observation:
    - The suffix of the array is in non-increasing order.
    - We need to find the first element (from the right) that breaks this order.
      This element is called the pivot.
    - Swap the pivot with the smallest element greater than it in the suffix.
    - Finally, reverse the suffix to make it as small as possible.

    Algorithm:
    ----------
    1. Traverse from right to left and find the first index 'idx' such that:
           nums[idx] < nums[idx + 1]
       This is the pivot.

    2. If no such index exists:
       - The array is already the largest permutation.
       - Reverse the entire array to obtain the smallest permutation.

    3. Otherwise:
       - Traverse from the end and find the first element greater than nums[idx].
       - Swap it with nums[idx].

    4. Reverse the subarray after idx.
       Since this suffix was originally in decreasing order, reversing it makes
       it the smallest possible increasing sequence.

    Example:
    --------
    nums = [1, 2, 7, 4, 3, 1]

    Step 1:
    Pivot = 2 (index = 1)

        [1, 2, 7, 4, 3, 1]
            ^

    Step 2:
    Find the first element greater than 2 from the right.
    It is 3.

        [1, 2, 7, 4, 3, 1]
                    ^

    Step 3:
    Swap 2 and 3.

        [1, 3, 7, 4, 2, 1]

    Step 4:
    Reverse everything after the pivot.

        [1, 3, 1, 2, 4, 7]

    This is the next lexicographical permutation.

    Time Complexity:
    ----------------
    O(n)
    - One pass to find the pivot.
    - One pass to find the successor.
    - One pass to reverse the suffix.

    Space Complexity:
    -----------------
    O(1)
    - In-place modification.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int n=nums.size(),idx=-1;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx=i;
                break;
            }
        }

        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=idx;i--)
        {
            if(nums[i]>nums[idx])
            {
                swap(nums[i],nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1,nums.end());
    }
};
