/*
Intuition:
-----------
Let the maximum depth of the tree be d.

Consider the path from the root (node 1) to any node at depth d.
Only the edges on this path matter.

Each edge can be assigned:
- weight 1 (odd)
- weight 2 (even)

The total path cost is odd if and only if the number of edges
assigned weight 1 is odd.

For a path containing d edges:
- Total assignments = 2^d
- Exactly half of them produce an odd sum.
  (Parity splits all assignments equally.)

Therefore:
    answer = 2^(d - 1)

Special case:
If n = 1, there are no edges, path cost = 0 (even),
so the answer is 0.

Algorithm:
-----------
1. Build the tree.
2. Find the maximum depth from node 1 using DFS.
3. If maxDepth == 0 return 0.
4. Return 2^(maxDepth - 1) mod 1e9+7.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int maxDepth = 0;
    void dfs(int node, int parent, int depth,
             vector<vector<int>>& adj) {
        maxDepth = max(maxDepth, depth);
        for (int next : adj[node]) {
            if (next != parent) {
                dfs(next, node, depth + 1, adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n == 1)
            return 0;
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0, 0, adj);
        return (int)modPow(2, maxDepth - 1);
    }
};
