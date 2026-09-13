/*
    Intuition:
    ------------
    We use a monotonic stack to efficiently count valid "shadow pairs".

    The stack stores:
        {value, frequency}

    and maintains values in non-decreasing order.

    `t` represents the total number of previous elements currently
    represented in the stack.

    For the current value `x`:

    1. Remove all values greater than `x`.
       These elements can no longer contribute to a valid pair with
       the current element.

    2. Initially, all remaining elements represented by the stack
       are potential pairs, so:
           add = t

    3. If `x` already exists at the top of the stack, its previous
       occurrences are excluded from the current count.

    4. Add the number of valid pairs to the answer.

    5. Update the frequency of `x` in the stack.

    This allows us to avoid checking every pair explicitly.

    Approach:
    ----------
    1. Maintain a monotonic increasing stack of `{value, frequency}`.
    2. Keep `t` as the number of active previous elements.
    3. Remove elements greater than the current value.
    4. Count valid previous elements using `t`.
    5. Exclude previous occurrences of the same value when required.
    6. Add the current value to the stack and continue.

    Time Complexity:
    O(n)

    Each element is pushed onto and removed from the stack at most once.

    Space Complexity:
    O(n)

    In the worst case, the stack can contain all distinct elements.
*/

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans=0;
        long long t=0;
        vector<pair<int,long long>>st;

        for(int x:nums)
        {
            while(!st.empty() && st.back().first>x)
            {
                t-=st.back().second;
                st.pop_back();
            }
            
            long long add=t;
            if(!st.empty() && st.back().first==x)
            {
                add-=st.back().second;
            }
            ans+=add;

            if(!st.empty() && st.back().first==x)
            {
                st.back().second++;
            }
            else
            {
                st.push_back({x,1});
            }
            t++;
        }
        return ans;
    }
};
