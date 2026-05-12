/*
Intuition:
-----------
We use Dynamic Programming.

Let:
dp[i][j] = length of Longest Common Subsequence (LCS)
            between first i characters of t1
            and first j characters of t2.

Transition:
------------
1. If current characters match:
   t1[i-1] == t2[j-1]

   Then we can include this character in LCS:
   dp[i][j] = 1 + dp[i-1][j-1]

2. If characters do not match:
   We have two choices:
   - Ignore current character from t1
   - Ignore current character from t2

   So:
   dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Base Case:
-----------
If either string is empty,
LCS length is 0.

Time Complexity:
-----------------
O(n * m)

Space Complexity:
------------------
O(n * m)
*/

class Solution
{
public:
    int longestCommonSubsequence(string t1, string t2)
    {
        int n=t1.size(),m=t2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(t1[i-1]==t2[j-1]) 
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
