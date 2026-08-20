/*
    Intuition:
    The matrix has two important properties:
    1. Each row is sorted from left to right.
    2. Each column is sorted from top to bottom.

    Start from the top-right corner.

    - If matrix[r][c] == target, we found the target.
    - If matrix[r][c] < target, everything to the left is also smaller,
      so we move down to the next row.
    - If matrix[r][c] > target, everything below is also larger,
      so we move left to the previous column.

    Example:
        matrix = {
            { 1,  4,  7, 11},
            { 2,  5,  8, 12},
            { 3,  6,  9, 16},
            {10, 13, 14, 17}
        }
        target = 9

        Start at 11.
        11 > 9  -> move left
        7  < 9  -> move down
        8  < 9  -> move down
        9 == 9  -> found

    Time Complexity: O(n + m)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int r=0,c=m-1;
        while(r<n && c>=0)
        {
            if(matrix[r][c]==target) return true;

            if(matrix[r][c]<target)
            {
                r++;
            }
            else
            {
                c--;
            }
        }
        return false;
    }
};
