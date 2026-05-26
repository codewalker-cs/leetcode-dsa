/*
Intuition:
We need to count how many characters appear in both lowercase
and uppercase forms in the given string.

Example:
word = "aaAbcBC"

'a' and 'A' both exist  -> special
'b' and 'B' both exist  -> special
'c' and 'C' both exist  -> special

Answer = 3

Approach:
1. Maintain two frequency arrays:
   - lo[26] for lowercase letters
   - up[26] for uppercase letters

2. Traverse the string:
   - If character is uppercase, increment its frequency in up[]
   - If character is lowercase, increment its frequency in lo[]

3. Iterate from 0 to 25:
   - If both lowercase and uppercase versions exist,
     increment the answer.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lo(26,0),up(26,0);

        for(char &c : word)
        {
            if(c>=65 && c<=90)
            {
                up[c-'A']++;
            }
            else if(c>=97 && c<=122)
            {
                lo[c-'a']++;
            }
        }

        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(up[i]>0 && lo[i]>0)
            {
                // If we have to take each pair of uppercase and lowercase of same letter
                //uniquely
                // ans+=min(up[i],lo[i]);
                ans++;
            }
        }

        return ans;
    }
};
