/*
    ------------------------------------------------------------
    Problem: Max Consecutive Ones III (LeetCode 1004)
    Approach: Sliding Window
    Time Complexity: O(n)
    Space Complexity: O(1)
    ------------------------------------------------------------

    Intuition:
    - We are allowed to flip at most 'k' zeros into ones.
    - Think of a window [l...r] that represents a valid subarray.
    - As we expand the window by moving 'r':
        • If we encounter a 0, we use one available flip (k--).
    - If we use more than k flips (k < 0), the window becomes invalid.
    - Shrink the window from the left until it becomes valid again.
        • If a removed element is 0, we regain one flip (k++).
    - Since the window is always valid after shrinking,
      update the maximum window length.

    Why it works:
    - Each element enters the window once and leaves once.
    - Therefore both pointers together move at most 2n times,
      giving an O(n) solution.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int len=0;

        while(r<nums.size())
        {
            if(nums[r]==0) k--;

            while(k<0)
            {
                if(nums[l]==0) k++;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
