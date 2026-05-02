// Intuition:
// We use DP to classify numbers into 3 categories:
// 0 -> valid but same after rotation (0,1,8)
// 1 -> invalid (contains 3,4,7)
// 2 -> valid and changes after rotation (2,5,6,9)
//
// For numbers >= 10:
// We split the number into two parts:
// i/10 (prefix) and i%10 (last digit)
// Then combine their states.
//
// If either part is invalid -> whole number is invalid
// Else if at least one part is "good" -> whole number is "good"

class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1,0);
        int ans=0;

        for(int i=0;i<=n;i++)
        {
            if(i<10)
            {
                if(i==3 || i==4 || i==7)
                {
                    dp[i]=1;
                }
                else if(i==2 || i==5 || i==6 || i==9)
                {
                    dp[i]=2;
                    ans++;
                }
            }
            else
            {
                int a=dp[i/10];
                int b=dp[i%10];

                if(a==1 || b==1)
                {
                    dp[i]=1;
                }
                else if(a==2 || b==2)
                {
                    dp[i]=2;
                    ans++;
                }
            }
        }
        return ans;
    }
};
