/*
-------------------------------------------------------
Intuition:
-------------------------------------------------------
We use two pointers to traverse both time series since
they are already sorted by timestamp.

- If timestamps are equal, add both values and move both pointers.
- If one timestamp is smaller, add the current value of that
  series with the current value of the other series and move
  the pointer having the smaller timestamp.
- After one series is exhausted, append the remaining elements.

Note:
This implementation follows the standard merge approach.
(For the original LeetCode problem, the "next available timestamp"
rule requires a different algorithm.)

-------------------------------------------------------
Algorithm:
-------------------------------------------------------
1. Initialize two pointers s1 and s2.
2. Compare timestamps of both series.
3. Add the corresponding summed value into the answer.
4. Move the appropriate pointer.
5. Append any remaining elements.

-------------------------------------------------------
Time Complexity:
-------------------------------------------------------
O(n + m)

-------------------------------------------------------
Space Complexity:
-------------------------------------------------------
O(1) (excluding the output array)

-------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n=series1.size(),m=series2.size();
        int s1=0,s2=0,sum=0;

        while(s1<n && s2<m)
        {
            if(series1[s1][0]<series2[s2][0])
            {
                ans.push_back({series1[s1][0],series1[s1][1]+series2[s2][1]});
                s1++;
            }
            else if(series1[s1][0]>series2[s2][0])
            {
                ans.push_back({series2[s2][0],series1[s1][1]+series2[s2][1]});
                s2++;              
            }
            else if(series1[s1][0]==series2[s2][0])
            {
                ans.push_back({series2[s2][0],series1[s1][1]+series2[s2][1]});
                s1++;
                s2++;
            }
        }

        while(s1<n)
        {
            ans.push_back(series1[s1]);
            s1++;
        }

        while(s2<m)
        {
            ans.push_back(series2[s2]);
            s2++;
        }

        return ans;
    }
};
