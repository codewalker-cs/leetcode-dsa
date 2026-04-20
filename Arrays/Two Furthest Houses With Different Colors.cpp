/*
Intuition:
We need the maximum distance between two houses having different colors.

Brute Force Idea:
Check every possible pair (i, j), where i < j.
If colors[i] != colors[j], update answer with (j - i).

Optimized Observation:
The maximum distance will always involve one of the ends.

Why?
If we want maximum distance, we want indices as far apart as possible.

So only two useful checks:
1. Compare every element with last house color.
   If colors[i] != colors[n-1], distance = (n-1 - i)

2. Compare every element with first house color.
   If colors[i] != colors[0], distance = i

Take maximum of both.

This avoids checking all pairs.

Time Complexity:
Brute Force: O(n^2)
Optimized: O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // int n=colors.size(),ans=0;

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(colors[i]!=colors[j])
        //         {
        //             ans=max(ans,j-i);
        //         }
        //     }
        // }
        // return ans;

        int n=colors.size(),ans=0;

        for(int i=0;i<=n-1;i++)
        {
            if(colors[i]!=colors[n-1])
            {
                ans=max(ans,n-1-i);
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(colors[i]!=colors[0])
            {
                ans=max(ans,i);
            }
        }
        
        return ans;
    }
};
