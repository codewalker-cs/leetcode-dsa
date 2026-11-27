/*
Intuition:
Each item has:
- A factor: items[i][0]
- A price: items[i][1]

The value of an item is the number of items whose factor is
divisible by its factor, including itself.

We use 0/1 knapsack DP to select items within the budget.
Then, we use the remaining budget to purchase additional items
at the cheapest price.

Approach:
1. Find the cheapest item price.
2. Calculate the value of each item by counting factors divisible
   by its factor.
3. Use 0/1 knapsack:
   - dp[cost] stores the maximum value achievable with exactly
     cost spent.
   - Iterate costs in descending order to avoid selecting the
     same item multiple times.
4. For every achievable cost:
   - Calculate how many additional cheapest items can be bought
     using the remaining budget.
   - Update the maximum answer.

Time Complexity: O(n^2 + n * budget)
Space Complexity: O(budget)
*/

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapest = INT_MAX;

        for (auto& item : items)
        {
            cheapest = min(cheapest, item[1]);
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            int factor = items[i][0];
            int price = items[i][1];
            int value = 1;

            for (int j = 0; j < n; j++)
            {
                if (i != j && items[j][0] % factor == 0)
                {
                    value++;
                }
            }

            for (int cost = budget; cost >= price; cost--)
            {
                if (dp[cost - price] != -1)
                {
                    dp[cost] = max(dp[cost], dp[cost - price] + value);
                }
            }
        }
        int answer = 0;

        for (int cost = 0; cost <= budget; cost++)
        {
            if (dp[cost] == -1) continue;
            int extra = (budget - cost) / cheapest;
            answer = max(answer, dp[cost] + extra);
        }
        return answer;
    }
};
