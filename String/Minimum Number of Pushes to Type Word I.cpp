/*
    Intuition
    ---------
    We want to minimize the total number of key presses needed to type the given word.

    Since each key can store up to 8 characters:
    - The first 8 assigned characters require 1 push.
    - The next 8 require 2 pushes.
    - The next 8 require 3 pushes, and so on.

    As every character in the word is unique (or equivalently, only the count matters),
    we only need the length of the string.

    Let:
        q = number of complete groups of 8 characters
        r = remaining characters

    Every complete group contributes:
        8 * (group_number)

    Using the arithmetic progression formula:
        8 * (1 + 2 + ... + q)
      = 8 * q * (q + 1) / 2
      = 4 * q * (q + 1)

    Remaining characters belong to the next group,
    so each costs (q + 1) pushes.

    Hence,
        Answer = 4*q*(q+1) + r*(q+1)
               = (4*q + r) * (q+1)

    Bit operations are used:
    - >>3  -> divide by 8
    - &7   -> modulo 8
    - <<2  -> multiply by 4


    Example Walkthrough
    -------------------
    word = "abcdefghijkl"

    Length = 12

    q = 12 >> 3 = 1
    r = 12 & 7  = 4

    First 8 characters:
        8 × 1 = 8 pushes

    Remaining 4 characters:
        4 × 2 = 8 pushes

    Total = 16

    Formula:
        ((1 << 2) + 4) * (1 + 1)
      = (4 + 4) * 2
      = 16


    Time Complexity
    ---------------
    O(1)

    Space Complexity
    ----------------
    O(1)
*/

class Solution {
public:
    int minimumPushes(string word) {
        auto q = word.size() >> 3;   // Complete groups of 8
        auto r = word.size() & 7;    // Remaining characters

        return ((q << 2) + r) * (q + 1);
    }
};
