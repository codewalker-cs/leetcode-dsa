/*
Intuition:
-----------
We need to check whether a string is a palindrome while ignoring:
- Case differences (uppercase vs lowercase)
- Non-alphanumeric characters (spaces, symbols, punctuation)

Instead of creating extra strings, we can solve this efficiently using
the two-pointer technique.

What is alphanumeric?
---------------------
Alphanumeric characters include:
- Alphabets: a–z, A–Z
- Digits: 0–9

C++ provides a built-in function:
isalnum(char c)

isalnum(c) returns true if 'c' is a letter or a digit, otherwise false.
This helps us skip spaces and special characters easily.

Approach (Two Pointer):
----------------------
1. Use two pointers:
   - Left pointer (i) starting from the beginning of the string
   - Right pointer (j) starting from the end of the string
2. Move the left pointer forward until it points to an alphanumeric character.
3. Move the right pointer backward until it points to an alphanumeric character.
4. Compare the characters at both pointers after converting them to lowercase.
5. If they are not equal, the string is NOT a palindrome.
6. Move both pointers inward and repeat.
7. If all comparisons match, the string IS a palindrome.

Time Complexity: O(n)
- Each character is visited at most once.

Space Complexity: O(1)
- No extra space is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // Skip non-alphanumeric characters from left
            while (i < j && !isalnum(s[i])) i++;

            // Skip non-alphanumeric characters from right
            while (i < j && !isalnum(s[j])) j--;

            // Compare characters (case-insensitive)
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            // Move pointers inward
            i++;
            j--;
        }
        return true;
    }
};

/*
I Originally used this code
================================================
class Solution {
public:
    bool isPalindrome(string s) {
        string p;
        string q;
        for(char i:s)
        {
            if(isalnum(i))
            {
                p+=(char) tolower(i);
            }
        }
        q=p;
        reverse(q.begin(),q.end());
        if(p==q)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
*/
