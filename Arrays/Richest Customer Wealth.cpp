/*
Intuition:
Each row represents a customer and each column represents the money
that customer has in a particular bank.

We calculate the total wealth of every customer by summing all values
in that row. While doing this, we keep track of the maximum wealth
encountered so far.

Example:
accounts = {
    {1, 2, 3},
    {3, 2, 1}
}

Customer 1 wealth = 1 + 2 + 3 = 6
Customer 2 wealth = 3 + 2 + 1 = 6

Maximum wealth = 6

Approach:
1. Traverse every row.
2. Compute the sum of elements in that row.
3. Update the answer with the maximum sum found.

Time Complexity:
O(n * m)
n = number of customers
m = number of banks

Space Complexity:
O(1)
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size(),ans=0;

        for(int i=0;i<n;i++)
        {
            int ma=0;
            for(int j=0;j<m;j++)
            {
                ma+=a[i][j];
            }
            ans=max(ans,ma);
        }
        return ans;
    }
};
