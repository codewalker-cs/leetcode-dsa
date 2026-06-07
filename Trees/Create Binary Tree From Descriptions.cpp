/*
Intuition:
-----------
Each value in the descriptions represents a unique tree node.

For every description:
[parent, child, isLeft]

1. Create parent and child nodes if they do not already exist.
2. Connect the child to the parent's left or right pointer.
3. Record every child value in a set.

The root of the tree is the only node that never appears as a child.
After building the entire tree, we simply find that node and return it.

Time Complexity: O(n)
Space Complexity: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> node;
        unordered_set<int> children;

        for(auto &des:descriptions)
        {
            int parent=des[0];
            int child=des[1];
            int left=des[2];

            if(!node.count(parent))
            {
                node[parent]=new TreeNode(parent);
            }

            if(!node.count(child))
            {
                node[child]=new TreeNode(child);
            }

            if(left)
            {
                node[parent]->left=node[child];
            }
            else
            {
                node[parent]->right=node[child];
            }

            children.insert(child);
        }

        for(auto &desc:descriptions)
        {
            int parent=desc[0];

            if(!children.count(parent))
            {
                return node[parent];
            }
        }
        return nullptr;
    }
};
