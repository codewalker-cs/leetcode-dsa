// File: rotate_string.cpp

/*
Intuition 1: Simulate Rotation
--------------------------------
We try to rotate string s step by step and check if it becomes equal to goal.

Rotation logic:
- Take the first character of s and move it to the end.
- Repeat this process at most n times (where n = size of string).

If at any point s == goal, then goal is a valid rotation.

Example:
s = "abcde"
Rotations:
"bcdea" -> "cdeab" -> "deabc" -> "eabcd" -> "abcde"

Time Complexity: O(n^2)
Reason: Each rotation takes O(n) and we do it n times.


Intuition 2: Concatenation Trick (Optimal)
------------------------------------------
If goal is a rotation of s, then it must be a substring of s + s.

Reason:
All possible rotations of s are contained within (s + s).

Example:
s = "abcde"
s + s = "abcdeabcde"

All rotations:
"bcdea", "cdeab", "deabc", "eabcd" are substrings of this.

So we just check:
Does (s + s) contain goal?

Time Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Approach 1: Brute Force Rotation
    bool rotateStringBrute(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;

        for (int i = 0; i < n; i++)
        {
            if (s == goal) return true;
            s += s[0];
            s.erase(s.begin());
        }
        return false;
    }

    // Approach 2: Optimal using concatenation
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};
