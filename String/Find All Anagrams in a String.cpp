/*
 * Problem: Find All Anagrams in a String
 *
 * Intuition:
 * -----------
 * We are given two strings:
 *   - s (main string)
 *   - p (pattern)
 *
 * We need to find all starting indices in 's' where a substring is an anagram of 'p'.
 *
 * Key Idea (Sliding Window + Frequency Count):
 * -------------------------------------------
 * 1. An anagram has the same frequency of characters.
 * 2. We maintain two frequency arrays of size 26:
 *      - freq1 → stores frequency of characters in 'p'
 *      - freq2 → stores frequency of current window in 's'
 *
 * 3. Use a sliding window of size = p.size():
 *      - Expand window by adding current character.
 *      - If window size exceeds, remove the leftmost character.
 *
 * 4. At each step, compare freq1 and freq2:
 *      - If equal → current window is an anagram → store starting index.
 *
 * Time Complexity:
 * ---------------
 * O(n * 26) ≈ O(n)
 *
 * Space Complexity:
 * ----------------
 * O(1) (fixed size arrays)
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int win=p.size();
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<win;i++)
        {
            freq1[p[i]-'a']++;
        }

        vector<int> ans;
        for(int i=0;i<s.size();i++)
        {
            freq2[s[i]-'a']++;
            if(i>=win)
            {
                freq2[s[i-win]-'a']--;
            }
            if(freq1==freq2)
            {
                ans.push_back(i - win + 1);
            }
        }
        return ans;
    }
};
