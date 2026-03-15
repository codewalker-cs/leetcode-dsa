/*
Intuition:
The last word is the sequence of characters after the final space.
To find its length efficiently:

1. Start from the end of the string.
2. Skip all trailing spaces.
3. Count characters until we encounter a space or reach the beginning.

This ensures we correctly handle cases like:
"Hello World"
"Hello World   "
"singleword"

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') i--;

        int ans = 0;
        while(i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};
