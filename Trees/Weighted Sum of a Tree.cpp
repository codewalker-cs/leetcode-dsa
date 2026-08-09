/*
    Intuition:
    -----------
    We need to calculate the weighted sum of every node.

    The weight of a node depends on its depth:
        weight = (height - depth + 1)

    So the main task is to find:
        1. The depth of every node.
        2. The maximum depth (height) of the tree.
        3. Use the formula to calculate the final weighted sum.

    Approach:
    ---------
    1. Build an adjacency list using the parent array.
       For every node i:
           parent[i] -> i

    2. Perform an iterative DFS using a stack.
       Store:
           {node, depth}

       The root node has depth 1.

    3. While traversing:
       - Store the depth of each node.
       - Update the maximum depth h.

    4. After finding the height, calculate the contribution
       of every node:

           contribution = nums[i] * (h - depth[i] + 1)

       Add all contributions to the answer.

    Example:
    --------
    Suppose the tree is:

            0
           / \
          1   2
         /
        3

    Depths:
        node 0 -> 1
        node 1 -> 2
        node 2 -> 2
        node 3 -> 3

    Height = 3

    Weights:
        node 0 -> 3 - 1 + 1 = 3
        node 1 -> 3 - 2 + 1 = 2
        node 2 -> 3 - 2 + 1 = 2
        node 3 -> 3 - 3 + 1 = 1

    Therefore:

        answer =
            nums[0] * 3 +
            nums[1] * 2 +
            nums[2] * 2 +
            nums[3] * 1

    Time Complexity:
    ----------------
    Building the tree: O(n)
    DFS traversal:     O(n)
    Calculating sum:    O(n)

    Overall: O(n)

    Space Complexity:
    -----------------
    Adjacency list: O(n)
    Depth array:    O(n)
    DFS stack:      O(n)

    Overall: O(n)
*/

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        long long sum=0;
        int h=1;
        vector<int> depth(n);
        vector<vector<int>> child(n);
        
        for(int i=1;i<n;i++)
        {
            child[parent[i]].push_back(i);
        }

        stack<pair<int,int>> st;
        st.push({0,1});

        while(!st.empty())
        {
            auto [node,d]=st.top();
            st.pop();
            depth[node]=d;
            h=max(h,depth[node]);

            for(int i:child[node])
            {
                st.push({i,d+1});
            }
        }
        
        for(int i=0;i<n;i++)
        {
            long long val=(h-depth[i]+1);
            sum+=(1LL*nums[i]*val);
        }
        return sum;
    }
};
