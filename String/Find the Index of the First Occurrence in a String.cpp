/*
    Intuition:

    We need to find the first position where `needle` occurs inside
    `haystack`.

    There are two common approaches:

    ---------------------------------------------------------------
    1. Brute Force
    ---------------------------------------------------------------

    We try every possible starting position of `needle` in `haystack`.

    Suppose:

        haystack = "sadbutsad"
        needle   = "sad"

    We start checking from index 0:

        haystack: s a d b u t s a d
                  ↑
        needle:   s a d

    Since all characters match, we return 0.

    If they don't match, we move to the next starting position and
    try again.

    We only need to check positions from 0 to `n - m`, because
    starting after that position would not leave enough characters
    for the complete `needle`.

    For example:

        n = 9
        m = 3

        Last possible starting index = 9 - 3 = 6

    So the loop is:

        for (int i = 0; i <= n - m; i++)

    At each position, we compare all `m` characters.

    Time Complexity:
        O(n * m)

    Space Complexity:
        O(1)


    ---------------------------------------------------------------
    2. KMP (Knuth-Morris-Pratt)
    ---------------------------------------------------------------

    Brute force can repeatedly compare the same characters.

    KMP avoids these unnecessary comparisons using an LPS array.

    LPS means:

        Longest Proper Prefix which is also a Suffix

    For every position in `needle`, `lps[i]` tells us how much of
    the already-matched pattern can still be reused after a mismatch.

    Example:

        needle = "aabaaab"

        lps = [0, 1, 0, 1, 2, 2, 3]

    Suppose we have matched several characters and then encounter
    a mismatch.

    Instead of starting from the beginning of `needle`, KMP uses:

        j = lps[j - 1]

    This allows us to continue from the longest prefix that could
    still match.

    Therefore, every character in both strings is processed only
    a limited number of times.

    Time Complexity:
        O(n + m)

    Space Complexity:
        O(m)
*/


class Solution {
public:

    /*
        Brute Force Approach

        Try every possible starting position and compare
        the complete needle from that position.
    */
    class Solution {
    public:
      int strStr(string haystack, string needle) {
          int n=haystack.size(),m=needle.size();
          if(m>n) return -1;
          for(int i=0;i<=n-m;i++)
          {
              if(needle[0]==haystack[i])
              {
                  int r=i;
                  while(r<i+m)
                  {
                      if(haystack[r]!=needle[r-i])
                      {
                          break;
                      }
                      r++;
                  }
                  if(r==i+m) return i;
              }
          }
          return -1;
      }
  };


    /*
        KMP Approach

        First construct the LPS array for `needle`.

        Then use the LPS array to skip unnecessary comparisons.
    */
    int kmp(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // Build LPS array.
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else if (len > 0) {
                len = lps[len - 1];
            }
            else {
                i++;
            }
        }

        // Search for needle in haystack.
        i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                // Complete needle found.
                if (j == m) {
                    return i - m;
                }
            }
            else if (j > 0) {
                // Use previously calculated LPS value.
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }

        return -1;
    }


    /*
        Main Function
    */
    int strStr(string haystack, string needle) {

        // Brute Force
        return bruteForce(haystack, needle);

        // KMP
        // return kmp(haystack, needle);
    }
};
