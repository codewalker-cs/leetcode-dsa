/*
Intuition:
- We need to find continuous segments where the two strings differ.
- Characters that are equal separate mismatched segments.
- Whenever we encounter a mismatch, start a segment.
- Continue until we reach an equal character or the end of the strings.
- Extract the corresponding substrings from both strings and store them.

Approach:
1. Initialize l = 0 and skip all matching characters from the beginning.
2. If the entire strings are equal, return an empty answer.
3. Traverse the strings starting from the first mismatch.
4. Whenever we find an equal character or reach the end:
   - Extract the mismatched segment from both strings.
   - Store the pair in the answer.
   - Move l forward to the next mismatch.
5. Return the answer.

Time Complexity: O(n) excluding the cost of storing substrings; O(n) total output size.
Space Complexity: O(n) for the answer.
*/

class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        vector<vector<string>> ans;
        int l=0;
        while(l<n && s1[l]==s2[l]) l++;
        if(l==n) return ans;
        for(int r=l+1;r<=n;r++)
        {
            if(r==n || s1[r]==s2[r])
            {
                ans.push_back({s1.substr(l,r-l),s2.substr(l,r-l)});
                l=r;
                while(l<n && s1[l]==s2[l]) l++;
                r=l;
            }
        }
        return ans;
    }
};
