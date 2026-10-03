/*
    Intuition:
    ------------
    We use a stack to store indices of unmatched parentheses.

    Initially, we push `-1` as a base index. This helps calculate
    the length of a valid substring that starts from index 0.

    For every character:

    1. If it is '(':
       Push its index because it may be matched by a future ')'.

    2. If it is ')':
       Pop the top element because we try to match this closing
       parenthesis with the most recent unmatched '('.

       After popping:
       - If the stack is empty, there is no '(' available to match
         this ')'. This index becomes the new boundary, so we push it.
       - Otherwise, the current valid substring starts immediately
         after `st.top()`.

         Its length is:

             i - st.top()

    We keep the maximum length found.

    Example:
        s = "(()"

        Indices:
            0  1  2
            (  (  )

        After processing index 2:
            stack = [-1, 0]

        Length:
            2 - 0 = 2

    Approach:
    ----------
    1. Push `-1` as the initial boundary.
    2. Push indices of '('.
    3. For ')', pop the matching '('.
    4. If the stack becomes empty, push the current index as a
       new invalid boundary.
    5. Otherwise, calculate the valid length using:
           i - st.top()
    6. Keep track of the maximum length.

    Time Complexity:
    O(n)

    Each index is pushed and popped at most once.

    Space Complexity:
    O(n)

    In the worst case, the stack can contain all indices.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> st;
        st.push(-1);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};
