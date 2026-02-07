/*
Intuition:
Two strings are anagrams if they contain the exact same characters
with the same frequencies.

We use a frequency array of size 26 (for lowercase letters).
1. Increment counts for characters in string s
2. Decrement counts for characters in string t

If s and t are anagrams, every increment will be canceled by a
corresponding decrement. So the frequency array should end up
containing only zeros.

We compare the resulting frequency array with a zero-initialized
array. If they match → anagram, otherwise → not anagram.

Time Complexity: O(n)
Space Complexity: O(1) (constant 26-length array)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0), need(26, 0);

        for (char &c : s) {
            freq[c - 'a']++;
        }

        for (char &c : t) {
            freq[c - 'a']--;
        }

        return freq == need;
    }
};
