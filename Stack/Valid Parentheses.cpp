/*
Valid Parentheses (LeetCode 20)
--------------------------------

Approach: Stack

------------------------------------------------------------
Intuition:
------------------------------------------------------------

We use a stack to track opening brackets.

1. Push opening brackets: '(', '{', '['
2. For closing brackets:
   - If stack is empty → invalid
   - If top doesn't match → invalid
   - Else pop

3. At the end:
   - If stack is empty → valid
   - Else → invalid

------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------------------------
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if(st.empty()) return false;

                if(c == ')' && st.top() == '(')
                    st.pop();
                else if(c == '}' && st.top() == '{')
                    st.pop();
                else if(c == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
