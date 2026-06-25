/*
    Problem: Daily Temperatures
    LeetCode: 739

    Intuition:
    ----------
    - Maintain a monotonic decreasing stack that stores indices.
    - Traverse the temperature array from left to right.
    - If the current temperature is greater than the temperature at the
      index on the top of the stack, then the current day is the next
      warmer day for that index.
    - The answer is simply the difference between the current index and
      the stored index.
    - Pop all such indices and continue.
    - Indices left in the stack never find a warmer temperature, so their
      answer remains 0.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n=t.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && t[i]>t[s.top()])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }

        // -----------------No need for this------------------
        // while(!s.empty())
        // {
        //     ans[s.top()]=0;
        //     s.pop();
        // }
        return ans;
    }
};
