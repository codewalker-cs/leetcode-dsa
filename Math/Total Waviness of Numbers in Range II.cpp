/*
Intuition:
-----------
We need:

    answer = waviness(num1) + waviness(num1 + 1) + ... + waviness(num2)

where a digit is counted if it is a peak or a valley.

Since num2 can be as large as 10^15, iterating through the range is impossible.

Digit DP:
---------
Let F(N) = total waviness of all numbers in [0, N].

Then:

    answer = F(num2) - F(num1 - 1)

While constructing a number from left to right, a digit can only be
classified as peak/valley once BOTH neighbors are known.

Suppose we already have:

    ... a b

and we append digit c.

Now digit b becomes fully determined.

b contributes +1 iff:

    (b > a && b > c)   // peak
or
    (b < a && b < c)   // valley

Therefore, whenever we append a new digit, we can immediately decide
whether the previous digit contributes to waviness.

DP State:
---------
pos      -> current digit index
tight    -> standard digit-DP tight flag
started  -> whether a non-leading-zero digit has appeared
prev2    -> digit at position i-2
prev1    -> digit at position i-1
len      -> number of actual digits chosen so far

DP returns:
    {countNumbers, totalWaviness}

When appending a digit:
    if len >= 2:
        evaluate prev1 using (prev2, prev1, currentDigit)

Complexity:
-----------
Positions <= 16 (because N <= 10^15)

State count:
    16 * 10 * 10 * 16 * 2

Very small.

Time:  O(16 * states * 10)
Memory: O(states)
*/

class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;

    Node dp[17][11][11][17][2];
    bool vis[17][11][11][17][2];

    Node dfs(int pos,int prev2,int prev1,int len,bool started,bool tight)
    {
        if (pos == (int)s.size())
        {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][len][started])
        {
            return dp[pos][prev2][prev1][len][started];
        }

        int limit=tight?(s[pos]-'0'):9;

        long long totalCnt=0;
        long long totalSum=0;

        for (int d=0;d<=limit;d++) {
            bool ntight=tight && (d == limit);

            if (!started && d == 0)
            {
                Node nxt = dfs(pos + 1,10,10,0,false,ntight);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
                continue;
            }

            if (!started)
            {
                Node nxt = dfs(pos + 1,10,d,1,true,ntight);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
            }
            else
            {
                int add=0;

                if (len>=2)
                {
                    if((prev1 > prev2 && prev1 > d)||(prev1 < prev2 && prev1 < d))
                    {
                        add = 1;
                    }
                }

                Node nxt = dfs(pos + 1,prev1,d,len + 1,true,ntight);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum + 1LL * add * nxt.cnt;
            }
        }

        Node res = {totalCnt, totalSum};

        if (!tight)
        {
            vis[pos][prev2][prev1][len][started] = true;
            dp[pos][prev2][prev1][len][started] = res;
        }

        return res;
    }

    long long solve(long long n)
    {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0,10,10,0,false,true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
