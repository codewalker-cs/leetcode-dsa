// Intuition:
// We want to convert the given string into a sequence formed by repeating "abc".
// The idea is to scan the string and try to match valid patterns:
//
// 1. If we see "abc" → no insertion needed.
// 2. If we see "ab" → we need to insert 'c'.
// 3. If we see "ac" → we need to insert 'b'.
// 4. If we see "bc" → we need to insert 'a'.
// 5. Otherwise (single character or invalid order) → we need 2 insertions
//    to complete the "abc" pattern.
//
// We greedily consume characters while counting how many insertions are required.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; )
        {
            if (i + 2 < n && word[i] == 'a' && word[i+1] == 'b' && word[i+2] == 'c')
            {
                i += 3;
            }
            else if (i + 1 < n && word[i] == 'a' && word[i+1] == 'b')
            {
                ans += 1;
                i += 2;
            }
            else if (i + 1 < n && word[i] == 'a' && word[i+1] == 'c')
            {
                ans += 1;
                i += 2;
            }
            else if (i + 1 < n && word[i] == 'b' && word[i+1] == 'c')
            {
                ans += 1;
                i += 2;
            }
            else
            {
                ans += 2;
                i += 1;
            }
        }
        return ans;
    }
};
