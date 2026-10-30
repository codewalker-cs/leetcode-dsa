/*
Intuition:
For each index, we need the distance to the closest occurrence of c.
We can calculate distances from the left and right separately.

Approach:
1. Traverse left to right and store the distance to the previous c.
2. Traverse right to left and update the answer with the minimum
   distance to the next c.

Time Complexity: O(n)
Space Complexity: O(n) for the answer array.
*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> ans(n,0);
        int prev=-n;

        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                prev=i;
            }
            ans[i]=i-prev;
        }
        prev=2*n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                prev=i;
            }
            ans[i]=min(ans[i],prev-i);
        }
        return ans;
    }
};
