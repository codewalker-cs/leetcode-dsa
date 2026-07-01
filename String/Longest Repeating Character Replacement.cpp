/*
    ------------------------------------------------------------
    Problem: Longest Repeating Character Replacement (LeetCode 424)
    Approach: Sliding Window + Frequency Array (Recomputing maxFreq)
    Time Complexity: O(26 * n) ≈ O(n)
    Space Complexity: O(26) ≈ O(1)
    ------------------------------------------------------------

    Intuition:
    - Maintain a sliding window [l...r].
    - Store the frequency of each uppercase character inside the
      current window using a frequency array.
    - Let maxFreq be the frequency of the most frequent character
      in the current window.
    - To make all characters in the window the same, replace every
      other character.
            Replacements Needed = Window Length - maxFreq
    - If the replacements required exceed k, the window becomes
      invalid, so shrink it from the left until it becomes valid.
    - Since removing a character may reduce the maximum frequency,
      recompute maxFreq after every shrink by scanning the
      frequency array.

    Why it works:
    - The character with the highest frequency is always the best
      choice to keep because it minimizes the number of replacements.
    - The window is always maintained such that it can be converted
      into a substring of identical characters using at most k
      replacements.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxfreq=0,maxlen=0;
        int hash[26]={0};
        for(int r=0;r<s.size();r++)
        {
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            
            while((r-l+1)-maxfreq>k)
            {
                hash[s[l]-'A']--;
                l++;
                maxfreq=0;
                for(int i=0;i<26;i++) maxfreq=max(maxfreq,hash[i]);
            }
            maxlen=max(maxlen,(r-l+1));
        }
        return maxlen;
    }
};
