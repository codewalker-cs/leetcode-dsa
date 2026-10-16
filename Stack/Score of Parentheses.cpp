/*
    Intuition:
    ------------
    The score of a balanced parentheses string follows three rules:

        1. "()" has a score of 1.
        2. AB has a score of score(A) + score(B).
        3. (A) has a score of 2 * score(A).

    We use a stack to store the score calculated before entering
    each new opening parenthesis.

    `curr` represents the score of the current parentheses group.

    When we encounter '(':
        - Push the current score onto the stack.
        - Reset `curr` to 0 to calculate the score inside this group.

    When we encounter ')':
        - If curr == 0, the current group is "()", so its score is 1.
        - Otherwise, the current group is "(A)", so its score is
          2 * curr.
        - Add this score to the score stored before the opening
          parenthesis.
        - Pop the previous score from the stack.

    Approach:
    ----------
    1. Initialize an empty stack and curr = 0.
    2. For '(':
        - Push curr onto the stack.
        - Reset curr to 0.
    3. For ')':
        - Calculate the score of the current group.
        - Add it to the previous score stored on the stack.
        - Pop the stack.
    4. Return curr.

    Time Complexity:
    O(n)

    Each character is processed once.

    Space Complexity:
    O(n)

    In the worst case, the stack contains O(n) elements.
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int curr=0;

        for(char c:s)
        {
            if(c=='(')
            {
                st.push(curr);
                curr=0;
            }
            else
            {
                int v=(curr==0)?1:2*curr;
                curr=st.top()+v;
                st.pop();
            }
        }
        return curr;
    }
};
