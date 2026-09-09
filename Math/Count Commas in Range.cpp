/*
    Intuition:
    ------------
    A comma appears in numbers starting from 1,000.

    For every power of 1,000:

        1,000       -> numbers have at least 1 comma
        1,000,000   -> numbers have at least 2 commas
        1,000,000,000 -> numbers have at least 3 commas

    For a given threshold `i`, every number from `i` to `n`
    contributes one comma.

    Therefore, the number of commas contributed by this threshold is:

        n - i + 1

    We keep multiplying `i` by 1,000 to consider the next comma
    position.

    Approach:
    ----------
    1. Start from 1,000, the first number containing a comma.
    2. For every power of 1,000 that is <= n:
           add (n - i + 1) to the answer.
    3. Multiply `i` by 1,000 to move to the next comma position.
    4. Return the total count.

    Example:
    n = 1005

    Numbers 1000 to 1005 each contain one comma.

    Count = 1005 - 1000 + 1 = 6

    Time Complexity:
    O(log₁₀(n))

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int countCommas(int n) {
        long long ans=0;

        for(long long i=1000;i<=n;i*=1000)
        {
            ans+=n-i+1;
        }
        return ans;
    }
};
