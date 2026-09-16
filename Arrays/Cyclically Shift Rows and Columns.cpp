/*
    Intuition:
    ------------
    We need to perform two types of cyclic shifts on the grid:

        1. Row shifts:
           Each row i is shifted by `rowshift[i]` positions.

        2. Column shifts:
           Each column i is shifted by `colshift[i]` positions.

    Instead of modifying the original grid directly, we first create
    `ans` containing all the row shifts.

    For a row shift, the element that should appear at position `j`
    comes from:

        grid[i][(j + rowshift[i]) % n]

    The modulo operation makes the shift cyclic.

    After all rows are shifted, we process each column.

    For column i, the element at row j comes from:

        ans[(j + colshift[i]) % n][i]

    We temporarily store the shifted column in `temp` so that
    modifying `ans` does not affect the values that still need to
    be read from that column.

    Approach:
    ----------
    1. Create an answer grid.
    2. Shift every row according to `rowshift`.
    3. For every column:
        - Store its shifted values in `temp`.
        - Copy `temp` back into that column.
    4. Return the resulting grid.

    Time Complexity:
    O(n²)

    Every cell is processed a constant number of times.

    Space Complexity:
    O(n²)

    The answer grid requires O(n²) space, and the temporary row/column
    vector requires O(n) additional space.
*/

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowshift, vector<int>& colshift) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp(n);
            for(int j=0;j<n;j++)
            {
                temp[j]=grid[i][(j+rowshift[i])%n];
            }
            ans.push_back(temp);
        }

        for(int i=0;i<n;i++)
        {
            vector<int> temp(n);
            for(int j=0;j<n;j++)
            {
                temp[j]=ans[(j+colshift[i])%n][i];
            }

            for(int k=0;k<temp.size();k++)
            {
                ans[k][i]=temp[k];
            }
        }
        return ans;
    }
};
