/*
Intuition:
This problem evaluates an expression given in Reverse Polish Notation (RPN).
We use a stack to process the tokens.

- If the token is a number:
    → Convert it from string to integer using stoi()
    → Push it onto the stack

- If the token is an operator (+, -, *, /):
    → Pop the top two elements from the stack
    → Let:
        b = top element (second operand)
        a = next top element (first operand)
    → Perform operation: a (operator) b
    → Push the result back onto the stack

Important:
Order matters for '-' and '/':
    a - b  (NOT b - a)
    a / b  (NOT b / a)

At the end:
The stack will contain exactly one element → the final result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &c : tokens)
        {
            if(c=="+" || c=="-" || c=="/" || c=="*")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                if(c=="+") st.push(a+b);
                else if(c=="-") st.push(a-b);
                else if(c=="/") st.push(a/b);
                else st.push(a*b);
            }
            else
            {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
