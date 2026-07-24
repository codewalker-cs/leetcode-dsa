/*
------------------------------------------------------------
Approach 1: Extra Matrix (Brute Force)
------------------------------------------------------------

Intuition:
Instead of modifying the original matrix immediately, first create a
duplicate matrix. This duplicate helps us remember the original
positions of all the zeroes.

Whenever we find a zero in the duplicate matrix, we make the entire
corresponding row and column zero in the original matrix.

Since we are checking zeroes from the copy, newly created zeroes in the
original matrix never affect our traversal.

Example:
Matrix:
1 1 1
1 0 1
1 1 1

Duplicate:
1 1 1
1 0 1
1 1 1

Found 0 at (1,1)

Zero row 1:
1 1 1
0 0 0
1 1 1

Zero column 1:
1 0 1
0 0 0
1 0 1

Final Answer:
1 0 1
0 0 0
1 0 1

Time Complexity:
O((N * M) * (N + M))

Space Complexity:
O(N * M)

------------------------------------------------------------
Approach 2: Optimal (Using First Row & First Column as Markers)
------------------------------------------------------------

Intuition:
Instead of using another matrix, we use the first row and first column
to store information about which rows and columns need to become zero.

Step 1:
Check separately whether the first row or first column originally
contains any zero because they will later be used as markers.

Step 2:
Traverse the remaining matrix (excluding first row and first column).

Whenever matrix[i][j] == 0,
mark:
matrix[i][0] = 0   -> Row i should become zero
matrix[0][j] = 0   -> Column j should become zero

Step 3:
Again traverse the inner matrix.
If its row marker or column marker is zero,
set that cell to zero.

Step 4:
Finally, if the original first row or first column had any zero,
make them completely zero.

Example:

Original Matrix

1 1 1
1 0 1
1 1 1

After marking

1 0 1
0 0 1
1 1 1

Now update inner cells using markers

1 0 1
0 0 0
1 0 1

Finally handle first row and first column (if required).

Why start from index 1?

Because the first row and first column are storing our markers.
If we zero them too early, we destroy the information needed for the
remaining cells.

Time Complexity:
O(N * M)

Space Complexity:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int n=matrix.size(),m=matrix[0].size();
        // vector<vector<int>> dup;
        // dup=matrix;

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(matrix[i][j]==0)
        //         {
        //             if(dup[i][j]==0)
        //             {
        //                 for(int k = 0; k < n; k++) matrix[k][j] = 0;
        //                 for(int k = 0; k < m; k++) matrix[i][k] = 0;
        //             }
        //         }
        //     }
        // }

        int n=matrix.size(),m=matrix[0].size();

        bool frowz=false,fcolz=false;

        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                fcolz=true;
                break;
            }
        }

        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]==0)
            {
                frowz=true;
                break;
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=1;j<m;j++) matrix[i][j]=0;
            }
        }

        for(int i=1;i<m;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=1;j<n;j++) matrix[j][i]=0;
            }
        }

        if(frowz)
        {
            for(int i=0;i<m;i++) matrix[0][i]=0;
        }

        if(fcolz)
        {
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
    }
};
