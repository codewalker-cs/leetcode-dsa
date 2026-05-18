/*
Intuition:
------------
This problem can be viewed as a graph traversal problem.

- Each index represents a node.
- From index `i`, we can jump to:
    1. i + arr[i]
    2. i - arr[i]

We need to determine whether we can reach any index
whose value is 0 starting from the given `start` index.

Approach:
------------
We use Depth First Search (DFS).

Base Cases:
1. If index goes out of bounds -> return false
2. If current value is 0 -> return true
3. If index is already visited -> return false

Why visited array?
------------
Without tracking visited indices, DFS may revisit
the same positions repeatedly and cause infinite recursion.

Complexity:
------------
Time Complexity  : O(n)
- Each index is visited at most once.

Space Complexity : O(n)
- Visited array + recursion stack.
*/

class Solution {
public:
    vector<int> v;

    bool dfs(vector<int> &arr,int start) {
        if(start<0 || start>arr.size()-1) return false;
        if(arr[start]==0) return true;
        if(v[start]) return false;
        v[start]=1;

        return dfs(arr,start-arr[start])||dfs(arr,start+arr[start]);
    }
    bool canReach(vector<int>& arr, int start) {
        v.resize(arr.size(),0);
        return dfs(arr,start);
    }
};
