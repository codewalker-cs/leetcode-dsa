/*
    Intuition:
    ------------
    A valid parentheses string must have every '(' matched with a
    corresponding ')'.

    We process the string from left to right.

    For every '(':
        Push it into the stack because it needs a future ')'.

    For every ')':
        - If there is an unmatched '(' in the stack, match them by
          popping the stack.
        - Otherwise, this ')' has no matching '(', so we need to add
          one '(' before it. We count this using `ans`.

    After processing the entire string, any '(' remaining in the
    stack needs a corresponding ')'. Therefore, we add the remaining
    stack size to the answer.

    Example:
        s = "()))(("

        Extra ')' = 1
        Remaining '(' = 2

        Answer = 1 + 2 = 3

    Approach:
    ----------
    1. Keep track of unmatched '(' using a stack.
    2. For an unmatched ')', increment the answer.
    3. After the traversal, add the number of remaining '('.
    4. Return the total number of insertions required.

    Time Complexity:
    O(n)

    Each character is processed once.

    Space Complexity:
    O(n)

    In the worst case, the stack contains all opening parentheses.
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(char &c:s)
        {
            if(c=='(')
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                {
                    ans++;
                }
                else
                {
                    st.pop();
                }
            }
        }

        if(!st.empty()) ans+=st.size();
        return ans;
    }
};
