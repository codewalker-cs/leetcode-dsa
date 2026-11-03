/*
Intuition:
- In one move, we can increment n - 1 elements by 1.
- Instead of incrementing multiple elements, we can think of
  keeping the maximum element unchanged and decrementing all
  other elements until they become equal to it.
- The minimum number of moves is therefore the sum of differences
  between the maximum element and every other element.

Approach:
1. Find the maximum element in the array.
2. Traverse the array.
3. For each element, add (maximum - element) to the answer.
4. Return the total number of moves.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int mx = *max_element(nums.begin(), nums.end());

        for (int i : nums) {
            if (i == mx) continue;
            ans += (mx - i);
        }

        return ans;
    }
};
