/*
    Intuition:
    ------------
    We need to generate all valid combinations of `n` pairs of
    parentheses.

    At any point, we can make two choices:

        1. Add '('
           We can add an opening bracket as long as we have used
           fewer than n opening brackets.

        2. Add ')'
           We can add a closing bracket only when there is an
           unmatched opening bracket:

                close < open

    This guarantees that we never create an invalid parentheses
    sequence.

    Once the current string has length `2 * n`, we have used exactly
    n opening and n closing brackets, so it is a valid answer.

    Approach:
    ----------
    `op` = number of opening brackets used
    `cl` = number of closing brackets used

    1. If the current string has length 2*n, store it.
    2. If `op < n`, add '(' and recurse.
    3. If `cl < op`, add ')' and recurse.
    4. Backtrack naturally because `curr + '('` and `curr + ')'`
       create new strings instead of modifying the same string.

    Time Complexity:
    O(Cn * n)

    where Cn is the nth Catalan number, because there are Cn valid
    parentheses combinations and each string has length 2*n.

    Space Complexity:
    O(Cn * n)

    This includes the space required to store all generated strings.
*/

class Solution {
public:
    void output(int n,int op,int cl,string curr,vector<string> &ans)
    {
        if(curr.length()==2*n)
        {
            ans.push_back(curr);
            return;
        }

        if(op<n)
        {
            output(n,op+1,cl,curr+"(",ans);
        }

        if(cl<op)
        {
            output(n,op,cl+1,curr+")",ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        output(n,0,0,"",ans);
        return ans;
    }
};
