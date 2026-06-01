/*
Approach:
- Sort the candy costs in increasing order.
- The two most expensive candies must always be paid for, so initialize
  the answer with them.
- Starting from the remaining candies, move from right to left.
- After paying for two candies, skip one candy because it can be taken
  for free under the offer.
- This effectively simulates buying candies in groups of three where the
  cheapest candy in each group becomes free.

Example:
cost = [1,2,3,4,5,6]

Sorted: [1,2,3,4,5,6]

Pay: 6 + 5
Remaining from right:
- Pay 3, Pay 2, Skip 1

Total = 6 + 5 + 3 + 2 = 16

Time Complexity: O(n log n)
- Sorting dominates the complexity.

Space Complexity: O(1)
- Ignoring the space used by the sorting algorithm.
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size(),ans=cost[n-1];

        if(n==1) return ans;
        
        ans+=cost[n-2];
        if(n==2) return ans;

        int i=n-4,c=0;
        while(i>=0)
        {
            c++;
            ans+=cost[i];
            if(c==2)
            {
                i--;
                c=0;
            }

            i--;
        }
        return ans;
    }
};

/*
Intuition:
- To minimize the total amount paid, we should maximize the value of the candies
  obtained for free.
- The offer says: for every 3 candies purchased, the cheapest among those 3 is free.
- Therefore, sort the costs in descending order and process candies in groups of 3.
- In each group:
    - Pay for the first two (most expensive) candies.
    - Skip the third candy since it is free.
- The sum of all paid candies is the minimum possible cost.

Time Complexity: O(n log n)
- Sorting dominates the complexity.

Space Complexity: O(1)
- Ignoring the space used by sorting.
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());

        int ans = 0;
        int n = cost.size();

        for (int i = 0; i < n; i++) {
            if (i % 3 != 2) {
                ans += cost[i];
            }
        }

        return ans;
    }
};
