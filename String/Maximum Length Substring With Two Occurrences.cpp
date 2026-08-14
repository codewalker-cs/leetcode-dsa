/*
    Intuition:
    We need to find the longest substring in which every character appears
    at most twice.

    This is a classic Sliding Window problem.

    We maintain a window [l, r) and store the frequency of every character
    inside the window.

    Step-by-step:
    1. Expand the window by adding s[r].
    2. Increase the frequency of s[r].
    3. If the frequency becomes greater than 2, the window is invalid.
    4. Move l forward until the frequency becomes at most 2 again.
    5. Update the maximum window length.

    Example:
    s = "bcbbbcba"

    When the window contains:
    "bcbbb"

    Frequency:
    b -> 3
    c -> 1

    The window is invalid because b appears 3 times.

    Move l forward until b appears at most twice.

    Since r represents the position just after the current window,
    the window length is:

        r - l

    Time Complexity:
        O(n)

    Each character is added to the window once and removed at most once.

    Space Complexity:
        O(1)

    We only store frequencies for 26 lowercase English letters.
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int> f(26,0);
        int l=0,r=0;
        int ans=0;

        while(r<n)
        {
            f[s[r]-'a']++;
            while(f[s[r]-'a']>2)
            {
                f[s[l]-'a']--;
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};
