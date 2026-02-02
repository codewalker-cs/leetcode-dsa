/*
Intuition:
----------
We are asked to check if any permutation of s1 exists as a substring in s2.

A permutation means:
same characters + same frequencies, order doesn't matter.

Instead of generating permutations (expensive),
we use a sliding window of size |s1| over s2.

Steps:
1. Count frequency of characters in s1 -> "need"
2. Maintain frequency of current window in s2 -> "window"
3. Compare the two arrays
4. Slide window by:
   - adding one character to the right
   - removing one character from the left

If at any point need == window,
a permutation exists.

Time Complexity: O(n)
Space Complexity: O(1) (26 letters only)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> need(26,0), window(26,0);

        for(char c : s1)
        {
            need[c-'a']++;
        }

        int k = s1.size();

        for(int i=0;i<k;i++)
        {
            window[s2[i]-'a']++;
        }

        if(need == window) 
        {
            return true;
        }

        for(int i=k;i<s2.size();i++)
        {
            window[s2[i]-'a']++;
            window[s2[i-k]-'a']--;
            if(need == window)
            {
                return true;
            }
        }
        return false;
    }
};
