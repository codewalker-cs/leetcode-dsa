/*
------------------------------------------------------------
Problem: Reverse Words in a String

Intuition:
- We want to reverse the order of words, NOT the characters.
- Extra spaces (leading, trailing, or multiple between words)
  should be ignored.
- Instead of splitting the string (which costs extra space),
  we traverse from the end and extract words one by one.

Approach:
1. Start scanning the string from the last index.
2. Skip any trailing spaces.
3. Mark the end of a word.
4. Move backward until a space is found — this marks the start.
5. Append the extracted word to the answer string.
6. Repeat until the entire string is processed.

Why this works:
- Words are collected in reverse order naturally.
- Spaces are handled cleanly.
- Time Complexity: O(n)
- Space Complexity: O(n) for the result string

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string reverseWords(string s)
    {
        int end=s.size()-1;
        string ans;
        while(end>=0)
        {
            while(end>=0 && s[end]==' ') end--;
            if(end<0) break;
            int start=end;
            while(start>=0 && s[start]!=' ') start--;
            
            if(!ans.empty()) ans+=' ';
            ans+=s.substr(start+1,end-start);
            end=start-1;
        }
        return ans;
    }
};
