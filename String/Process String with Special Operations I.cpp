/*
Intuition:
We build the final string while scanning the input from left to right.

Each character represents an operation:

- Normal character:
  Append it to the current result.

- '*':
  Remove the last character from the current result.

- '#':
  Duplicate the entire current result.

- '%':
  Reverse the current result.

Since every operation only depends on the string built so far,
we can directly simulate the process using a single result string.

Example:
s = "ab#c%*"

'a' -> "a"
'b' -> "ab"
'#' -> "abab"
'c' -> "ababc"
'%' -> "cbaba"
'*' -> "cbab"

Final result = "cbab"

Time Complexity: O(n + total generated string operations)

The '#' operation copies the current string and '%'
reverses the current string, so the running time depends
on the size of the intermediate strings as well.

Space Complexity: O(m)

where m is the length of the final generated string.
*/

class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                int s1=res.size();
                res=res.substr(0,s1-1);
            }
            else if(s[i]=='#')
            {
                res+=res;
            }
            else if(s[i]=='%')
            {
                reverse(res.begin(),res.end());
            }
            else
            {
                res+=s[i];
            }
        }
        return res;
    }
};

//or

class Solution {
public:
    string processStr(string s) {
        string res;

        for (char ch : s) {
            if (ch == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            else if (ch == '#') {
                res += res;
            }
            else if (ch == '%') {
                reverse(res.begin(), res.end());
            }
            else {
                res.push_back(ch);
            }
        }

        return res;
    }
};
