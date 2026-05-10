// Intuition:
// The array is already sorted, but negative numbers become positive after squaring.
// Example:
// nums = [-7, -3, 2, 3, 11]
//
// Squaring gives:
// [49, 9, 4, 9, 121]
//
// This is NOT sorted.
//
// Observation:
// The largest square will always come from either:
// 1) the most negative number (left side)
// 2) the largest positive number (right side)
//
// So we use two pointers:
// left  -> start of array
// right -> end of array
//
// Compare abs(nums[left]) and abs(nums[right]).
// Whichever is larger produces the larger square.
// Place it at the end of the answer array.
//
// Since we fill from back to front, the final array becomes sorted.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while (left <= right)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare)
            {
                ans[idx] = leftSquare;
                left++;
            }
            else
            {
                ans[idx] = rightSquare;
                right--;
            }
            idx--;
        }
        return ans;
    }
};
