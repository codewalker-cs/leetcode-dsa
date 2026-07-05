/*
=========================================================
LeetCode 2108. Find First Palindromic String in the Array
=========================================================

Problem:
Given an array of strings `words`, return the first palindromic
string in the array. If there is no such string, return "".

Example:
Input:  ["abc","car","ada","racecar","cool"]
Output: "ada"

---------------------------------------------------------
Intuition
---------------------------------------------------------
A palindrome reads the same from left to right and
right to left.

For every word:
1. Check whether it is a palindrome.
2. If yes, immediately return it.
3. If no palindrome is found after checking all words,
   return an empty string.

Since we need the FIRST palindrome, there is no reason
to continue searching once one is found.

---------------------------------------------------------
Algorithm
---------------------------------------------------------
1. Traverse every string in the array.
2. For each string:
      - Compare characters from both ends.
      - If any pair doesn't match, it isn't a palindrome.
      - Otherwise it is a palindrome.
3. Return the first palindrome found.
4. If none exists, return "".

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
Let:
n = number of strings
m = maximum length of a string

Checking one palindrome takes O(m).

Overall:
O(n * m)

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(1)

Only a few pointers are used.
=========================================================
*/

class Solution {
public:
    bool isPalindrome(string &s)
    {
        int left=0, right=s.size()-1;
        while (left<right)
        {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (string &word : words)
        {
            if (isPalindrome(word)) return word;
        }
        return "";
    }
};
