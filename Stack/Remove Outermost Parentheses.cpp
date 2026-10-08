/*
    Intuition:
    ------------
    Every primitive parentheses string has exactly one outermost
    opening '(' and one outermost closing ')'.

    We can identify these outermost parentheses using a `depth`
    counter.

    For every character:

        '(':
            Increase depth first.
            If the new depth is greater than 1, this '(' is not an
            outermost parenthesis, so we keep it.

        ')':
            If the current depth is greater than 1, this ')' is not
            an outermost parenthesis, so we keep it.
            Then decrease depth.

    For example:

        s = "(()())()"

        Primitive parts:
            "(()())" + "()"

        Remove outermost parentheses:
            "()()" + ""

        Result:
            "()()"

    Approach:
    ----------
    1. Maintain the current nesting depth.
    2. For '(':
        - Increase depth.
        - Add it to the answer only if depth > 1.
    3. For ')':
        - Add it only if depth > 1.
        - Decrease depth.
    4. Return the resulting string.

    Time Complexity:
    O(n)

    Each character is processed exactly once.

    Space Complexity:
    O(n)

    The answer string can contain up to O(n) characters.
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int d=0;

        for(char &c:s)
        {
            if(c=='(')
            {
                d++;
                if(d>1)
                {
                    ans+=c;
                }
            }
            else
            {
                if(d>1)
                {
                    ans+=c;
                }
                d--;
            }
        }
        return ans;
    }
};
