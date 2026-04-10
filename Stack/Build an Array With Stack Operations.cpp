/*
Build an Array With Stack Operations (LeetCode 1441)
---------------------------------------------------

Intuition:
---------------------------------------------------
We simulate numbers from 1 to n.

We maintain a pointer 'j' for target array.

For each number i:
- If i == target[j]:
    → Push (keep it)
    → move j forward
- Else:
    → Push + Pop (discard it)

Stop once we finish building target.

No actual stack is needed — only operations tracking.
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 0;

        for (int i = 1; i <= n && j < target.size(); i++) {
            if (i == target[j]) {
                ans.push_back("Push");
                j++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};
