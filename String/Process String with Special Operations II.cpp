/*
    LeetCode 3614 - Process String with Special Operations II

    Intuition:
    ----------
    Constructing the final string directly is impossible because
    the length can become extremely large after multiple '#' operations.

    Instead of building the string, we:

    1. Compute the final length after processing all operations.
    2. If k is outside the final string, return '.'.
    3. Traverse the operations in reverse and map the required
       index k back to the corresponding index before each operation.

    Reverse Processing:
    -------------------
    '*' :
        Forward -> removes last character.
        Reverse -> length increases by 1.

    '#' :
        Forward -> duplicates the entire string.
        Reverse -> determine whether k lies in the first or second half.

    '%' :
        Forward -> reverses the string.
        Reverse -> reversal is its own inverse.
                  k becomes (len - 1 - k).

    letter :
        Forward -> append character.
        Reverse -> if k points to this appended character,
                   return it. Otherwise shrink length by 1.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long len=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                len=max(0LL,len-1);
            }
            else if(s[i]=='#')
            {
                len*=2;
            }
            else if(s[i]!='%')
            {
                len++;
            }
        }

        if(len<=k) return '.';

        for(int i=n-1;i>=0;i--)
        {
            char c=s[i];

            if(c=='*')
            {
                len++;
            }
            else if(c=='#')
            {
                long long half=len/2;

                if(k>=half) k-=half;
                len=half;
            }
            else if(c=='%')
            {
                k=len-1-k;
            }
            else
            {
                if(k==len-1) return s[i];
                len--;
            }
        }
        return '.';
    }
};
