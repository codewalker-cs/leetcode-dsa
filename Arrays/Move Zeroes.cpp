/*
    Problem: 283. Move Zeroes
    Difficulty: Easy

    Intuition:
    - The goal is to move all zeroes to the end while maintaining the
      relative order of non-zero elements.
    - First, find the position of the first zero in the array.
    - Use another pointer to scan the remaining elements.
    - Whenever a non-zero element is found, move it to the earliest
      available zero position and replace its original position with zero.
    - Advance the left pointer to the next zero position.
    - Since both pointers only move forward, each element is processed
      at most once.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        while (l < n && nums[l] != 0)
            l++;

        for (int r = l + 1; r < n; r++) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                nums[r] = 0;

                while (l < n && nums[l] != 0)
                    l++;
            }
        }
    }
};
