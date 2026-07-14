/*
=========================================================
LeetCode 1668. Maximum Repeating Substring
=========================================================

Approach 1: Using string::find()

Intuition:
----------
We need to find the maximum integer k such that

    word repeated k times

appears as a substring of sequence.

Start with one copy of 'word'. As long as the current repeated
string exists inside 'sequence', increment the answer and append
another copy of 'word'.

Example:
--------
sequence = "ababc"
word = "ab"

cur = "ab"       -> found, ans = 1
cur = "abab"     -> found, ans = 2
cur = "ababab"   -> not found

Answer = 2

Time Complexity:
----------------
O(n * k)

Space Complexity:
-----------------
O(m * k)


---------------------------------------------------------

Approach 2: Dynamic Programming

Intuition:
----------
Let dp[i] denote the maximum number of consecutive repetitions
of 'word' ending exactly at index i.

If the substring ending at i matches 'word':

    dp[i] = 1

If another complete occurrence ended exactly m positions earlier:

    dp[i] += dp[i - m]

The maximum value in dp is the answer.

Example:
--------
sequence = "ababc"
word = "ab"

Index:  0 1 2 3 4
Chars:  a b a b c

dp:

i = 1
"ab" matches
dp[1] = 1

i = 3
"ab" matches
dp[3] = dp[1] + 1 = 2

Answer = 2

Time Complexity:
----------------
O(n * m)

Space Complexity:
-----------------
O(n)

=========================================================
*/


// =====================================================
// Approach 1 : Using string::find()
// =====================================================

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string cur = word;
        int ans = 0;

        while (sequence.find(cur) != string::npos) {
            ans++;
            cur += word;
        }

        return ans;
    }
};


// =====================================================
// Approach 2 : Dynamic Programming
// =====================================================

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();

        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = m - 1; i < n; i++) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (sequence[i - m + 1 + j] != word[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                dp[i] = 1;

                if (i >= m)
                    dp[i] += dp[i - m];

                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
