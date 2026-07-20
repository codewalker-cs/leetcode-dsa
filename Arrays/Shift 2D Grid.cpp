/*
Intuition:
-----------
Instead of shifting the grid one step at a time, observe that the grid
can be viewed as a single 1D array of size (n * m).

For every element:
1. Convert its (row, col) into a 1D index.
2. Shift the index by k positions.
3. Convert the new index back into (row, col).

This avoids performing k separate shifts and directly places every
element in its final position.

Example:
--------
grid = [[1,2,3],
        [4,5,6],
        [7,8,9]]

Flattened:
[1,2,3,4,5,6,7,8,9]

k = 1

New positions:
1 -> index 1
2 -> index 2
...
9 -> index 0

Result:
[[9,1,2],
 [3,4,5],
 [6,7,8]]

Time Complexity:
----------------
O(n * m)

Space Complexity:
-----------------
O(n * m)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();

        // for(int i=0;i<k;i++)
        // {
        //     int temp=grid[0][0];
        //     for(int j=0;j<n;j++)
        //     {
        //         for(int p=0;p<m;p++)
        //         {
        //             if(p==m-1 && j==n-1)
        //             {
        //                 swap(grid[0][0],temp);
        //             }
        //             else if(p==m-1)
        //             {
        //                 swap(grid[j+1][0],temp);
        //             }
        //             else
        //             {
        //                 swap(grid[j][p+1],temp);
        //             }
        //         }
        //     }
        // }

        // return grid;

        k%=(n*m);
        vector<vector<int>> ans(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int idx=i*m+j;
                int idxn=(idx+k)%(n*m);
                ans[idxn/m][idxn%m]=grid[i][j];
            }
        }
        return ans;
    }
};
