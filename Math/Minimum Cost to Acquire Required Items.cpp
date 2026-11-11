/*
Intuition:
- There are three ways to satisfy the requirements:
  1. Buy type 1 and type 2 items separately.
  2. Buy type 3 items for the common requirements and cover
     the remaining requirements separately.
  3. Buy only type 3 items to satisfy both requirements, even
     if some units exceed what is needed.
- Calculate the cost of all three possibilities and choose
  the minimum.

Approach:
1. Calculate o1: Buy all type 1 and type 2 items separately.
2. Calculate o2:
   - Buy min(need1, need2) type 3 items.
   - Buy the remaining items individually.
3. Calculate o3: Buy max(need1, need2) type 3 items.
4. Return the minimum of the three costs.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long o1=1LL*need1*cost1+1LL*need2*cost2;
        int common=min(need1,need2);
        long long o2=1LL*common*costBoth+1LL*(need1-common)*cost1+1LL*(need2-common)*cost2;
        int extra=max(need1,need2);
        long long o3=1LL*extra*costBoth;

        return min({o1,o2,o3});
    }
};
