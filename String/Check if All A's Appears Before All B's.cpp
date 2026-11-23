/*
Intuition:
The string is valid if no 'a' appears after a 'b'.

Approach:
1. Maintain a boolean variable b to track whether we have encountered
   the first 'b'.
2. Traverse the string:
   - If the current character is 'b', set b = true.
   - If b is true and the current character is 'a', return false.
3. If the traversal completes, return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkString(string s) {
        bool b=false;
        for(char c:s)
        {
            if(c=='b') b=true;
            if(b==true && c=='a') return false;
        }
        return true;
    }
};
