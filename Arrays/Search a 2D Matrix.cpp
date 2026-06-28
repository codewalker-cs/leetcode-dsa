/*
    ============================================================================
                                Search a 2D Matrix
    ============================================================================

    There are two optimal approaches.

    ----------------------------------------------------------------------------
    Approach 1: Binary Search on Rows + Binary Search inside the Row
    ----------------------------------------------------------------------------

    Intuition:
    ----------
    Since:
    1. Every row is sorted in increasing order.
    2. The first element of each row is greater than the last element of the
       previous row.

    We can first determine which row may contain the target.

    Example:

        1   3   5   7
        10 11 16 20
        23 30 34 60

    target = 16

    Step 1:
        Binary search over the rows.

            Row 0 -> [1 ... 7]
            Row 1 -> [10 ... 20]   <- target lies here

    Step 2:
        Perform a normal binary search inside that row.

    Time Complexity:
        O(log(rows) + log(cols))

    Space Complexity:
        O(1)


    ----------------------------------------------------------------------------
    Approach 2 (Optimal): Treat Matrix as a Sorted 1D Array
    ----------------------------------------------------------------------------

    Intuition:
    ----------
    Since every row starts with a value greater than the previous row's last
    value, the whole matrix is globally sorted.

    Example:

        1   3   5   7
        10 11 16 20
        23 30 34 60

    can be viewed as

        [1,3,5,7,10,11,16,20,23,30,34,60]

    We DO NOT actually flatten the matrix.

    Instead, convert a 1D index back into 2D coordinates.

        row = index / number_of_columns
        col = index % number_of_columns

    Example:

        index = 6
        cols = 4

        row = 6 / 4 = 1
        col = 6 % 4 = 2

        matrix[1][2] = 16

    Perform one binary search over indices
    [0 ... rows * cols - 1].

    Time Complexity:
        O(log(rows * cols))

    Space Complexity:
        O(1)
*/

class Solution {
public:

    // ------------------------------------------------------------------------
    // Approach 1
    // ------------------------------------------------------------------------
    bool searchMatrix_RowBinarySearch(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = -1;

        int left = 0;
        int right = rows - 1;

        // Find the candidate row.
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][cols - 1]) {
                row = mid;
                break;
            }
            else if (target < matrix[mid][0]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        if (row == -1)
            return false;

        // Binary search inside the row.
        left = 0;
        right = cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }

    // ------------------------------------------------------------------------
    // Approach 2 (Optimal)
    // ------------------------------------------------------------------------
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
