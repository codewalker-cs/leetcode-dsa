/*
Intuition:
- If the string is already sorted, no operations are needed.
- If the string has length 2 and is not sorted, it is impossible
  to sort it using the allowed operation.
- Let a be the minimum character and b be the maximum character.
- The minimum number of operations depends on the positions of
  these extreme characters.

Approach:
1. If the string is already sorted, return 0.
2. If its length is 2 and it is not sorted, return -1.
3. Find the minimum and maximum characters.
4. If the first character is the minimum or the last character
   is the maximum, return 1.
5. If the minimum or maximum appears in an interior position,
   return 2.
6. Otherwise, return 3.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n==2) return -1;

        char a=*min_element(s.begin(),s.end()),b=*max_element(s.begin(),s.end());
        
        if(s[0]==a || s[n-1]==b) return 1;
        for(int i=1;i<n-1;i++) if(s[i]==b || s[i]==a) return 2;
        return 3;
    }
};
