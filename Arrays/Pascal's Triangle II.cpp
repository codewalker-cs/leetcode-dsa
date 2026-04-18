// Pascal's Triangle II
// Build rows one by one using previous row.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre = {1};

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> ans;

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    ans.push_back(1);
                else
                    ans.push_back(pre[j - 1] + pre[j]);
            }

            pre = ans;
        }

        return pre;
    }
};
