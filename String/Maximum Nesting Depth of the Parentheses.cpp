/*
    Intuition:
    The nesting depth is simply the number of currently open
    parentheses.

    - '(' increases the depth.
    - ')' decreases the depth.
    - Keep track of the maximum depth reached.

    Example:
    s = "(1+(2*3)+((8)/4))+1"

    Depth progression:
    1 -> 2 -> 1 -> 2 -> 3 -> 2 -> 1

    Maximum depth = 3

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    int maxDepth(string s) {
        int ans=0,fans=0;

        for(char &c:s)
        {
            if(c=='(')
            {
                ans++;
                fans=max(fans,ans);
            }
            else if(c==')')
            {
                ans--;
            }
        }
        return fans;
    }
};
