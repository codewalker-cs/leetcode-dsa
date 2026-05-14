/*
    Intuition:
    A "good" array of size n must contain:

    [1, 2, 3, ..., n-1, n-1]

    That means:
    - Numbers from 1 to n-2 appear exactly once
    - Number (n-1) appears exactly twice

    Approach:
    1. Sort the array
    2. Check whether:
       nums[0] = 1
       nums[1] = 2
       ...
       nums[n-2] = n-1
    3. Finally verify that the last element is also (n-1)

    Time Complexity: O(n log n)
    Space Complexity: O(1) excluding sorting space
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        for (int i=0;i<n-1;i++)
        {
            if (nums[i] != i+1)
            {
                return false;
            }
        }

        return nums[n-1] == n-1;
    }
};
