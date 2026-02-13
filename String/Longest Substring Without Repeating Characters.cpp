/*
Intuition:

We want the longest substring with no repeating characters.

We use a sliding window [l, r].

For every character:
- If we’ve seen it before inside the current window,
  move l right after its last occurrence.
- Update the window length.

We store the last index of each character in an array.
This guarantees each character is processed once.

Time Complexity: O(n)
Space Complexity: O(1)  (constant 256 ASCII table)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256,-1);
        int len=0,l=0;
        for(int r=0;r<s.size();r++)
        {
            if(vis[s[r]]!=-1)
            {
                l=max(l,vis[s[r]]+1);
            }
            len=max(len,r-l+1);
            vis[s[r]]=r;
        }
        return len;
    }
};
