/*
Intuition:
The direct way to rotate a matrix by 90° clockwise is to create another matrix,
but that requires O(n²) extra space.

Instead, observe two important transformations:

1. Transpose the matrix
   - Convert every row into a column.
   - Swap matrix[i][j] with matrix[j][i] for all i < j.

2. Reverse every row
   - After transposition, reversing each row places every element
     in its correct rotated position.

These two operations together achieve a 90° clockwise rotation
using only constant extra space.

---------------------------------------------------------
Example Walkthrough:

Input Matrix:

1 2 3
4 5 6
7 8 9

Step 1: Transpose

1 4 7
2 5 8
3 6 9

Step 2: Reverse every row

7 4 1
8 5 2
9 6 3

This is the required 90° clockwise rotated matrix.

---------------------------------------------------------
Why does this work?

Original Position:
(i, j)

After Transpose:
(j, i)

After Reversing each Row:
(j, n - 1 - i)

This is exactly the coordinate transformation for
a 90° clockwise rotation.

---------------------------------------------------------
Time Complexity:
Transposition : O(n²)
Reverse Rows  : O(n²)

Overall: O(n²)

---------------------------------------------------------
Space Complexity:
O(1)

The rotation is performed in-place without using
any extra matrix.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++) reverse(matrix[i].begin(),matrix[i].end());
    }
};

/*
Intuition:
We want to rotate the matrix 90 degrees clockwise.

Observation:
- The first column becomes the first row (reversed).
- More formally:
    matrix[i][j] → newMatrix[j][n - 1 - i]

My Approach:
- You iterate column-wise (fix i as column index).
- Then traverse rows in reverse (j from n-1 → 0).
- Fill row 'i' of new matrix using variable k.

This effectively builds the rotated matrix correctly.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> m=matrix;

        for(int i=0;i<n;i++)
        {
            int k=0;
            for(int j=n-1;j>=0;j--)
            {
                m[i][k]=matrix[j][i];
                k++;
            }
        }
        matrix=m;
    }
};

/*
Cleaner mapping without extra variable:
m[i][n - 1 - j] = matrix[j][i]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> m(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][n - 1 - j] = matrix[j][i];
            }
        }

        matrix = m;
    }
};
