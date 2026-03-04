/*
Intuition:
A position (i, j) in the matrix is called special if:
1. mat[i][j] == 1
2. Row i contains exactly one '1'
3. Column j contains exactly one '1'

If we try to determine this while traversing the matrix once,
we may make incorrect decisions because later cells might contain
additional 1s in the same row or column.

So the correct approach is:

Step 1:
Count how many 1s exist in each row.

Step 2:
Count how many 1s exist in each column.

Step 3:
Traverse the matrix again and check if a cell satisfies:
    mat[i][j] == 1
    row[i] == 1
    col[j] == 1

If all conditions hold, then it is a special position.

Time Complexity:
O(m * n)

Space Complexity:
O(m + n)
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
