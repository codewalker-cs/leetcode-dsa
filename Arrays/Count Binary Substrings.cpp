/*
    Two Pointer Approach

    We move through the string group by group.

    i = start of first group
    j = end of first group
    k = end of second group

    For every adjacent group pair:
        answer += min(length1, length2)

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int i = 0;
        int count = 0;

        while(i < n) {
            
            // Step 1: Find first group
            int j = i;
            while(j < n && s[j] == s[i]) {
                j++;
            }
            
            int len1 = j - i;
            
            // Step 2: Find second group
            int k = j;
            while(k < n && k < n && s[k] == s[j]) {
                k++;
            }
            
            int len2 = k - j;
            
            // Step 3: Add valid substrings
            count += min(len1, len2);
            
            // Step 4: Move i to next group
            i = j;
        }
        
        return count;
    }
};
