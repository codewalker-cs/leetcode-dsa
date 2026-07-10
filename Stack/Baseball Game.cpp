/*
    ------------------------------------------------------------
    Problem: Baseball Game
    LeetCode: 682
    ------------------------------------------------------------

    Intuition:
    We need to keep track of all valid scores in the order they
    are recorded. Since each operation only affects the most
    recent scores, a stack is the perfect data structure.

    Operations:
    1. Integer -> Push the score onto the stack.
    2. "+"     -> Push the sum of the last two valid scores.
    3. "D"     -> Push double the previous valid score.
    4. "C"     -> Remove the previous valid score.

    For the '+' operation, we temporarily remove the top element
    to access the second last score, restore it, and then push
    their sum.

    ------------------------------------------------------------
    Example:
    operations = ["5","2","C","D","+"]

    Stack = []

    "5" -> [5]
    "2" -> [5, 2]
    "C" -> [5]
    "D" -> [5, 10]
    "+" -> Last two scores = 10 and 5
           Push 15
           Stack = [5, 10, 15]

    Sum = 5 + 10 + 15 = 30

    ------------------------------------------------------------
    Algorithm:
    1. Create an empty stack.
    2. Traverse each operation.
       - If it is an integer, push it.
       - If it is "C", pop the top score.
       - If it is "D", push twice the top score.
       - If it is "+", compute the sum of the last two scores
         and push it.
    3. Pop all elements from the stack while adding them to the
       final answer.
    4. Return the total score.

    ------------------------------------------------------------
    Time Complexity: O(n)
    - Each operation is processed once.

    Space Complexity: O(n)
    - In the worst case, every score is stored in the stack.
    ------------------------------------------------------------
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int n=operations.size();

        for(int i=0;i<n;i++)
        {
            if(operations[i]=="+")
            {
                int f=s.top();
                s.pop();
                int sec=s.top();
                
                s.push(f);
                s.push(f+sec);
            }
            else if(operations[i]=="D")
            {
                s.push(s.top()*2);
            }
            else if(operations[i]=="C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }

        int ans=0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
