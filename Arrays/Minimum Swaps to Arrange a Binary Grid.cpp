/*
LeetCode 1536 - Minimum Swaps to Arrange a Binary Grid
======================================================

We are given a binary grid.
We must arrange rows using ONLY adjacent swaps so that:

For every row i:
    All elements from column (i+1) to (n-1) must be 0.

Meaning:
    Row i must have at least (n - i - 1) trailing zeros.

---------------------------------------------------------------------

APPROACH 1 — Direct Grid Simulation (Brute Force Style)
--------------------------------------------------------

Intuition:
- For each row i:
    1. Check if it satisfies the condition.
    2. If not, search below for a row that satisfies it.
    3. Bring that row upward using adjacent swaps.
    4. Add (k - i) to answer.

Time Complexity: O(n^3)
Space Complexity: O(1)

---------------------------------------------------------------------

APPROACH 2 — Optimized Greedy Using Trailing Zero Count
--------------------------------------------------------

Intuition:
- Precompute trailing zeros for each row.
- For each row i:
    1. Required trailing zeros = (n - i - 1)
    2. Find first row j >= i satisfying requirement.
    3. Bubble it upward.
    4. Add (j - i) swaps.

Why Greedy Works:
- Always bring the nearest valid row.
- Minimizes swaps.
- Maintains optimal structure.

Time Complexity: O(n^2)
Space Complexity: O(n)

---------------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(),count=0;

        for(int i=0;i<n;i++)
        {
            bool flag=false;
            for(int j=i+1;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    flag=true;
                    break;
                }
            }

            if(flag)
            {
                bool flag2=false;
                for(int k=i+1;k<n;k++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(grid[k][j]!=0)
                        {
                            break;
                        }
                        else if(grid[k][j]==0 && j==n-1)
                        {
                            flag2=true;
                            break;
                        }
                    }
                    if(flag2)
                    {
                        count+=(k-i);
                        int n1=i,n2=k;
                        while(n2!=n1)
                        {
                            swap(grid[n2],grid[n2-1]);
                            n2--;
                        }
                        break;
                    }
                    else if(k==n-1 && flag2==false)
                    {
                        return -1;
                    }
                }
            }
        }
        return count;

        // int n = grid.size();
        // vector<int> trailing(n);
        
        // for(int i = 0; i < n; i++) {
        //     int count = 0;
        //     for(int j = n - 1; j >= 0; j--) {
        //         if(grid[i][j] == 0)
        //             count++;
        //         else
        //             break;
        //     }
        //     trailing[i] = count;
        // }
        
        // int swaps = 0;
        
        // for(int i = 0; i < n; i++) {
        //     int required = n - i - 1;
        //     int j = i;
            
        //     while(j < n && trailing[j] < required)
        //         j++;
            
        //     if(j == n) 
        //         return -1;
            
        //     while(j > i) {
        //         swap(trailing[j], trailing[j - 1]);
        //         swaps++;
        //         j--;
        //     }
        // }
        // return swaps;
    }
};
