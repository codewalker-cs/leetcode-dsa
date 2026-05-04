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
