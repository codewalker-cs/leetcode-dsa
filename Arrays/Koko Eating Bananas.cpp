/*
    Problem: 875. Koko Eating Bananas

    Intuition 1 (Brute Force)
    -------------------------
    - Try every possible eating speed k from 1 to max(piles).
    - For each speed, calculate the total hours required.
    - The first speed that finishes within h hours is the answer.

    Time Complexity: O(n * maxPile)
    Space Complexity: O(1)

    ------------------------------------------------------------

    Intuition 2 (Optimal - Binary Search)
    ------------------------------------
    Observations:
    1. If Koko can finish all bananas with speed k,
       then she can also finish with any speed > k.
    2. If Koko cannot finish with speed k,
       then she also cannot finish with any speed < k.

    This monotonic behavior allows Binary Search.

    Search Space:
    - Minimum possible speed = 1
    - Maximum possible speed = max(piles)

    For every middle speed:
    - Compute the total hours required.
    - Hours for one pile:
          ceil(pile / k)
      Using integer arithmetic:
          (pile + k - 1) / k

    If totalHours <= h:
        -> k is a valid answer.
        -> Try to find a smaller valid speed.
    Else:
        -> Increase the eating speed.

    Time Complexity:
        O(n * log(maxPile))

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        int res=r;
        if(n==h) return r;

        while(l<=r)
        {
            int k=l+((r-l)/2);
            int totalvalue=0;

            for(int &i:piles)
            {
                totalvalue+=(i+k-1)/k;
            }

            if(totalvalue<=h)
            {
                res=k;
                r=k-1;
            }
            else
            {
                l=k+1;
            }
        }
        return res;
    }
};
