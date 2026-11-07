/*
Intuition:
- We need to count substrings that do NOT contain "abc" as a
  consecutive sequence.
- Maintain a left boundary l representing the starting index
  of the current valid window.
- Whenever "abc" is found ending at index r, move l to r - 1.
  This removes all substrings ending at r that contain this "abc".
- For every right endpoint r, there are (r - l + 1) valid
  substrings ending at that index.

Approach:
1. Initialize ans = 0 and l = 0.
2. Traverse the string using r.
3. If the last three characters form "abc", update l = r - 1.
4. Add r - l + 1 to the answer.
5. Return ans.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    long long countValidSubstrings(string s) {
        int n=s.size();
        long long ans=0;
        int l=0;

        for(int r=0;r<n;r++)
        {
            if(r>=2 && s[r-2]=='a' && s[r-1]=='b' && s[r]=='c') l=r-1;
            ans+=r-l+1;
        }
        return ans;
    }
};
