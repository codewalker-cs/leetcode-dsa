/*
    Intuition:
    ------------
    Consider one operation:

        source[i] = source[i] + source[j] - delta
        source[j] = delta

    Before the operation, the contribution of these two elements is:

        source[i] + source[j]

    After the operation:

        (source[i] + source[j] - delta) + delta
        = source[i] + source[j]

    Therefore, the total sum of the array never changes.

    The important observation is that this operation is powerful
    enough to redistribute the values between any two indices.

    For example, if two values are:

        a, b

    we can transform them into:

        a + b - delta, delta

    for any integer `delta`.

    So the only invariant that matters is the total sum.

    Therefore, `source` can be transformed into `target` if and only if:

        sum(source) == sum(target)

    We use `long long` because the sum can be larger than the range
    of an individual integer.

    Approach:
    ----------
    1. Calculate the sum of all elements in `source`.
    2. Calculate the sum of all elements in `target`.
    3. If the sums are equal, return true.
    4. Otherwise, return false.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1=0,s2=0;
        for(int i=0;i<source.size();i++) s1+=source[i];
        for(int i=0;i<target.size();i++) s2+=target[i];

        return s1==s2;
    }
};
