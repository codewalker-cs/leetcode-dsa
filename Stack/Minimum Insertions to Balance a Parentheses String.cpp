/*
    Intuition:
    ------------
    In this problem, every opening parenthesis '(' must be matched
    with two consecutive closing parentheses '))'.

    We maintain:
        open  = number of unmatched opening parentheses
        ans   = minimum insertions required so far

    For every character:

    1. If s[i] == '(':
       - If the previous character was ')' and it was not part of
         a complete pair, we need to insert one ')' to complete it.
       - Increase the number of unmatched opening parentheses.

    2. If s[i] == ')':
       - If the next character is also ')', we have a complete
         closing pair.
       - Otherwise, insert one ')' to complete the pair.
       - If there is no unmatched opening parenthesis, insert '('
         to match this closing pair.
       - Otherwise, match the pair with an existing '('.

    Approach:
    ----------
    1. Traverse the string from left to right.
    2. Handle each closing pair '))' together.
    3. Insert missing parentheses whenever necessary.
    4. Add two closing parentheses for every unmatched '(' remaining
       at the end.

    Time Complexity:
    O(n)

    Each character is processed at most once.

    Space Complexity:
    O(1)

    Only a few integer variables are used.
*/

class Solution {
public:
    int minInsertions(string s) {
        int ans=0,o=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                o++;
            }
            else
            {
                if(i+1<s.size() && s[i+1]==')')
                {
                    i++;
                }
                else
                {
                    ans++;
                }

                if(o>0)
                {
                    o--;
                }
                else
                {
                    ans++;
                }
            }
        }
        ans+=(o*2);
        return ans;
    }
};
