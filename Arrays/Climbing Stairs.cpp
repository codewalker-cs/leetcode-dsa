/*
    ------------------------------------------------------------
    Problem: Climbing Stairs (LeetCode 70)
    ------------------------------------------------------------

    Intuition:
    - To reach the i-th stair, there are only two possible ways:
        1. Come from the (i-1)-th stair by taking 1 step.
        2. Come from the (i-2)-th stair by taking 2 steps.
    - Therefore, the total number of ways to reach the i-th stair
      is the sum of the ways to reach the previous two stairs.

      dp[i] = dp[i-1] + dp[i-2]

    ------------------------------------------------------------
    Example:
    n = 5

    Base Cases:
    dp[0] = 1   (One way: stay at the ground)
    dp[1] = 1   (One way: take one step)

    Build the DP table:

    i = 2
    dp[2] = dp[1] + dp[0]
           = 1 + 1
           = 2

    i = 3
    dp[3] = dp[2] + dp[1]
           = 2 + 1
           = 3

    i = 4
    dp[4] = dp[3] + dp[2]
           = 3 + 2
           = 5

    i = 5
    dp[5] = dp[4] + dp[3]
           = 5 + 3
           = 8

    Answer = 8

    ------------------------------------------------------------
    Time Complexity: O(n)

    Space Complexity: O(n)

    ------------------------------------------------------------
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
