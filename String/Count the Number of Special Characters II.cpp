/*
Intuition:
-----------
A character is called "special" if:
1. Its lowercase version appears in the string.
2. Its uppercase version also appears.
3. Every lowercase occurrence comes before the first uppercase occurrence.

Approach:
---------
1. Store:
   - last occurrence of every lowercase character.
   - first occurrence of every uppercase character.

2. Traverse the string:
   - For lowercase letters:
       update their latest index.
   - For uppercase letters:
       store only the first occurrence.

3. For every character from 'a' to 'z':
   - Check:
       lowercase exists
       uppercase exists
       last lowercase index < first uppercase index

4. Count all such characters.

Time Complexity:
----------------
O(n + 26) -> O(n)

Space Complexity:
-----------------
O(26) -> O(1)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lo(26,-1);
        vector<int> up(26,-1);
        int n=word.size();

        for(int i=0;i<n;i++)
        {
            if(word[i]<=122 && word[i]>=97)
            {
                lo[word[i]-'a']=i;
            }
            else if(word[i]<=90 && word[i]>=65)
            {
                if(up[word[i]-'A']==-1)
                {
                    up[word[i]-'A']=i;
                }
            }
        }

        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(lo[i]!=-1 && up[i]!=-1 && lo[i]<up[i])
            {
                ans++;
            }
        }

        return ans;
    }
};
