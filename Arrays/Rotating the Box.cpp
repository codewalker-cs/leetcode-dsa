// Intuition:
// We can solve this in 2 steps:
//
// 1. Simulate gravity on every row of the original box.
//    Since after rotation, stones fall downward, it is easier to first
//    move stones to the right side in each row.
//
//    Example:
//    #.#*..##
//
//    becomes:
//    .##*..##
//
//    We use a pointer `empty` that stores the rightmost available
//    position where a stone can fall before hitting an obstacle.
//
// 2. Rotate the matrix 90 degrees clockwise.
//    Original cell (i, j) goes to (j, n-1-i)
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();

        for (int i = 0; i < n; i++)
        {
            int empty = m - 1;
            for (int j = m - 1; j >= 0; j--)
            {
                if (g[i][j] == '*')
                {
                    empty = j - 1;
                }
                else if (g[i][j] == '#')
                {
                    swap(g[i][j], g[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[j][n - 1 - i] = g[i][j];
            }
        }
        return ans;
    }
};
