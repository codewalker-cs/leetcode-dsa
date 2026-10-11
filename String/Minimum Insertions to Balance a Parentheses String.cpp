/*
    Intuition:
    ------------
    Every opening parenthesis '(' requires two consecutive closing
    parentheses '))' to make the string balanced.

    We maintain two variables:

        o   = number of unmatched opening parentheses
        ans = minimum insertions required

    For every character:

    1. If s[i] == '(':
       Increase `o` because this opening parenthesis needs two
       closing parentheses.

    2. If s[i] == ')':
       Check whether the next character is also ')'.

       - If yes, we have a complete closing pair, so skip the next
         character by incrementing i.
       - Otherwise, insert one ')' to complete the closing pair.

       Now we need to match this closing pair with an opening '('.

       - If an unmatched opening parenthesis exists, consume one.
       - Otherwise, insert one '(' to match the closing pair.

    After processing the string, every unmatched '(' requires two
    closing parentheses, so we add `o * 2` to the answer.

    Approach:
    ----------
    1. Traverse the string.
    2. Count unmatched opening parentheses.
    3. Process closing parentheses in pairs.
    4. Insert missing parentheses whenever necessary.
    5. Add two insertions for every unmatched opening parenthesis.

    Time Complexity:
    O(n)

    Each character is processed at most once.

    Space Complexity:
    O(1)

    Only two integer variables are used.
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
