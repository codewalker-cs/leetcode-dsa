/*
------------------------------------------------------------
Problem: Longest Common Prefix
------------------------------------------------------------

Intuition:
We start by assuming that the first string in the array is the
longest possible common prefix.

Then we compare this prefix with every other string in the list.

For each string:
1. Compare characters one by one.
2. Stop when characters mismatch OR when the end of either
   string is reached.
3. The index where mismatch occurs determines the new length
   of the common prefix.
4. Shrink the prefix using erase().

If the prefix ever becomes empty, we immediately return "",
because no common prefix exists.

Example:
Input: ["flower","flow","flight"]

Initial prefix = "flower"

Compare with "flow"
→ common part = "flow"

Compare with "flight"
→ common part = "fl"

Output = "fl"

------------------------------------------------------------
Time Complexity:  O(n * m)
n = number of strings
m = length of shortest string

Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while(j < s.size() && j < strs[i].size())
            {
                if(s[j] != strs[i][j])
                    break;
                j++;
            }
            s.erase(j);
            if(s.empty())
                return "";
        }

        return s;
    }
};
