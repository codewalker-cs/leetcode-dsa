/*
    Intuition:
    ------------
    The string represents a sequence of digits that we need to visit
    on a circular dial.

    First, we calculate the total cost of following the original
    sequence:

        0 -> s[0] -> s[1] -> ... -> s[n-1]

    The distance between two digits on the circular dial is:

        min(|a - b|, 10 - |a - b|)

    Now, we consider moving one digit `s[i]` to the end of the
    sequence.

    Originally, we have the transition:

        pre -> oldf

    where:
        pre  = digit before s[i]
        oldf = s[i]

    After moving s[i] to the end, this transition becomes:

        pre -> newf

    where:
        newf = last digit of the original string

    Therefore, the new cost is:

        total
        - distance(pre, oldf)
        + distance(pre, newf)

    We try this for every possible position and keep the minimum.

    Approach:
    ----------
    1. Define a helper function to calculate the minimum circular
       distance between two digits.
    2. Calculate the total cost of the original sequence.
    3. For every index i:
        - Find the digit immediately before it.
        - Remove the old transition `pre -> s[i]`.
        - Add the new transition `pre -> last digit`.
        - Update the minimum answer.
    4. Return the minimum cost.

    Time Complexity:
    O(n)

    We calculate the original cost in O(n) and check every possible
    rotation in another O(n).

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int minRotations(int n, string s) {
        auto dist=[](int a,int b)
        {
            int diff=abs(a-b);
            return min(diff,10-diff);
        };

        int t=0;
        int curr=0;

        for(char c:s)
        {
            int d=c-'0';
            t+=dist(curr,d);
            curr=d;
        }

        int ans=t;
        for(int i=0;i<n;i++)
        {
            int pre=(i==0)?0:s[i-1]-'0';
            int oldf=s[i]-'0';
            int newf=s[n-1]-'0';

            int cost=t-dist(pre,oldf)+dist(pre,newf);
            ans=min(ans,cost);
        }
        return ans;
    }
};
