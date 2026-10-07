/*
    Intuition:
    ------------
    We use dynamic programming to keep track of the best alternating
    sums that can be formed while processing the array.

    For every number `x`, we maintain four states:

        pnod:
            Best value when the current subsequence has an odd number
            of selected elements and the last operation is negative.

        mnod:
            Best value when the current subsequence has an even number
            of selected elements and the last operation is negative.

        pd:
            Best value when the current subsequence has an odd number
            of selected elements and the last operation is positive.

        md:
            Best value when the current subsequence has an even number
            of selected elements and the last operation is positive.

    The transitions decide whether the current number should be
    added, subtracted, or used to start a new subsequence.

    `neg` represents an impossible state. We use a sufficiently
    small value instead of LLONG_MIN directly to avoid overflow
    during arithmetic operations.

    For every number x:

        npnod = mnod - x

        nmnod = max(x, pnod + x)

        npd   = max(md - x, pnod)

        nmd   = max(pd + x, mnod)

    We update all states simultaneously using temporary variables
    because every new state must be calculated from the previous
    iteration's states.

    Approach:
    ----------
    1. Initialize all DP states to a very small value.
    2. For every element:
        - Calculate the four new states.
        - Replace the old states with the new ones.
        - Update the global maximum.
    3. Return the maximum value found.

    Time Complexity:
    O(n)

    Each element is processed once with constant-time transitions.

    Space Complexity:
    O(1)

    Only a fixed number of DP states are maintained.
*/

class Solution {
public:
    using ll=long long;
    long long maxAlternatingSum(vector<int>& nums) {
        const ll neg=LLONG_MIN/4;

        ll pnod=neg,mnod=neg;
        ll pd=neg,md=neg;
        ll ans=neg;

        for(int x:nums)
        {
            ll npnod=mnod-x;
            ll nmnod=max((ll)x,pnod+x);

            ll npd=max(md-x,pnod);
            ll nmd=max(pd+x,mnod);

            pnod=npnod;
            mnod=nmnod;
            pd=npd;
            md=nmd;

            ans=max({ans,pnod,mnod,pd,md});
        }
        
        return ans;
    }
};
