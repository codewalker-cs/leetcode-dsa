/*
    Intuition:
    ------------
    We need to count the minimum number of deletions required to
    remove consecutive duplicate elements.

    We traverse the array from left to right and compare each element
    with the previous element.

    If:
        nums[i] == nums[i - 1]

    then the current element is a duplicate of the previous element,
    so we increment the deletion count.

    Otherwise, no deletion is needed for the current element.

    Approach:
    ----------
    1. Initialize the deletion count to 0.
    2. Traverse the array starting from index 1.
    3. If the current element equals the previous element, increment
       the deletion count.
    4. Return the total number of deletions.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                ans++;
            }
        }

        return ans;
    }
};
