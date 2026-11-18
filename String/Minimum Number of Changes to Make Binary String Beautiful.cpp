/*
Intuition:
A beautiful string can be divided into even-length substrings
containing only identical characters.

Approach:
1. Divide the string into pairs of adjacent characters.
2. If both characters in a pair are different, one change is
   required to make them equal.
3. Count the number of such pairs.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minChanges(string s) {
        int ans=0;

        for(int i=0;i<s.size();i+=2)
        {
            if(s[i]!=s[i+1])
            {
                ans++;
            }
        }

        return ans;
    }
};
