/*
  Intuition:
  - Use an additional stack to keep track of the minimum value
  at every level of the main stack.
  - When pushing a value:
    * Push it into the main stack.
    * Push min(current value, previous minimum) into minSt.
  - The top of minSt always stores the minimum element
    currently present in the stack.

  Time Complexity:
  - push()   : O(1)
  - pop()    : O(1)
  - top()    : O(1)
  - getMin() : O(1)

  Space Complexity:
  - O(n)
*/

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int val) {
        st.push(val);

        if (minSt.empty()) {
            minSt.push(val);
        } else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
