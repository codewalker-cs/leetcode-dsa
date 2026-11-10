/*
Intuition:
- A server can communicate with another server if they are in the
  same row or the same column.
- Instead of checking every server against every other server,
  count the number of servers in each row and column.
- A server can communicate if its row or column contains more
  than one server.

Approach:
1. Create two arrays:
   - row[i] stores the number of servers in row i.
   - col[j] stores the number of servers in column j.
2. Traverse the grid and count servers in each row and column.
3. Traverse the grid again:
   - If grid[i][j] == 1 and (row[i] > 1 || col[j] > 1),
     increment the answer.
4. Return the answer.

Time Complexity: O(m * n)
Space Complexity: O(m + n)
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
