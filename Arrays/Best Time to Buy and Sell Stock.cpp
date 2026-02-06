/*
Intuition:
We want to buy at the lowest price before a future higher price.
Track the minimum price seen so far and compute profit at each step.

profit today = current price - minimum price seen before today

We update the answer greedily in one pass.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int buy = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};
