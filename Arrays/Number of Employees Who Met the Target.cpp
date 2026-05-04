/*
Intuition:
We are given a list of working hours for employees and a target number of hours.
We need to count how many employees have worked at least the target number of hours.

Approach:
- Initialize a counter (ans) to 0.
- Iterate through each element in the 'hours' vector.
- If the current value is greater than or equal to the target, increment the counter.
- Finally, return the counter.

Time Complexity: O(n)
- We traverse the array once.

Space Complexity: O(1)
- No extra space is used apart from variables.
*/

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;

        for (int &i : hours)
        {
            if (i >= target)
            {
                ans++;
            }
        }
        return ans;
    }
};
