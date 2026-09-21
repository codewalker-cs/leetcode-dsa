/*
    Intuition:
    ------------
    Each character has a value based on its position in the reversed
    alphabet:

        a -> 26
        b -> 25
        c -> 24
        ...
        z -> 1

    For a character s[i], its reversed alphabet position is:

        26 - (s[i] - 'a')

    Since the position in the string is 1-indexed, the position of
    s[i] is:

        i + 1

    Therefore, the contribution of each character is:

        (i + 1) * (26 - (s[i] - 'a'))

    We simply calculate this value for every character and add it
    to the answer.

    Approach:
    ----------
    1. Traverse the string from left to right.
    2. Calculate the reversed alphabet value of each character.
    3. Multiply it by its 1-indexed position.
    4. Add the result to the answer.
    5. Return the total reverse degree.

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans+=((i+1)*(26-(s[i]-'a')));
        }
        return ans;
    }
};
