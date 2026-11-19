/*
Intuition:
We use tree DP to calculate the maximum achievable score for
each node based on the scores of its children.

Approach:
1. Construct an adjacency list using the parent array.
2. Perform DFS starting from the root (node 0).
3. For each node:
   - Initialize total with its own score.
   - Recursively calculate the DP values of all its children.
   - Add all child DP values to total.
   - Find the minimum DP value among its children.
4. If op[u] == 1, subtract the minimum child DP value.
5. Otherwise, subtract the minimum child DP value only if it is negative.
6. Store the result in dp[u] and return dp[0].

Time Complexity: O(n)
Space Complexity: O(n)
    - Adjacency list: O(n)
    - DP array: O(n)
    - Recursion stack: O(n) in the worst case
*/

class Solution {
public:
    long long dfs(int u,vector<vector<int>>& adj,vector<int>& op,vector<int>& score,vector<long long>& dp)
    {
        long long total=score[u];
        long long mn=LLONG_MAX;

        for(int v:adj[u])
        {
            dfs(v,adj,op,score,dp);
            total+=dp[v];
            mn=min(mn,dp[v]);
        }

        if(adj[u].empty()) return dp[u]=score[u];
        
        if(op[u]==1)
        {
            total-=mn;
        }
        else
        {
            if(mn<0)
            {
                total-=mn;
            }
        }
        return dp[u]=total;
    }
    
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>> adj(n);

        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
        }
        vector<long long> dp(n,0);
            return (int)dfs(0,adj,op,score,dp);
    }
};
