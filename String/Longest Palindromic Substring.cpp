/*
===========================================================
PROBLEM: Longest Palindromic Substring
===========================================================

We discuss TWO approaches:

-----------------------------------------------------------
1) BRUTE FORCE (O(n^3))
-----------------------------------------------------------
Intuition:
- Generate all substrings (l → r)
- Check each substring if it is palindrome
- Keep track of maximum length palindrome

Why slow?
- Total substrings = O(n^2)
- Checking palindrome = O(n)
→ Total = O(n^3)

-----------------------------------------------------------
2) EXPAND AROUND CENTER (O(n^2))
-----------------------------------------------------------
Intuition:
- A palindrome expands from its center

Two types of centers:
1. Odd length → center at single character (i, i)
2. Even length → center between two characters (i, i+1)

For each index:
- Expand outward while characters match
- Update longest palindrome found

Why better?
- Each expansion takes O(n)
- Done for n centers
→ Total = O(n^2)
- No extra space required (O(1))

===========================================================
*/

class Solution {
public:
    // bool checkpalin(string &s, int l, int r)
    // {
    //     while(l <= r)
    //     {
    //         if(s[l] != s[r])
    //             return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     string ans = "";

    //     for(int l = 0; l < n; l++)
    //     {
    //         for(int r = l; r < n; r++)
    //         {
    //             if(checkpalin(s, l, r))
    //             {
    //                 if(r - l + 1 > ans.size())
    //                 {
    //                     ans = s.substr(l, r - l + 1);
    //                 }
    //             }
    //         }
    //     }

    //     return ans;        
    // }
    string expand(string &s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);

            if(odd.size() > ans.size()) ans = odd;
            if(even.size() > ans.size()) ans = even;
        }

        return ans;
    }
};
