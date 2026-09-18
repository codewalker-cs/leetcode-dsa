/*
    Intuition:
    ------------
    Excel columns work like a base-26 number system:

        A  -> 1
        B  -> 2
        ...
        Z  -> 26
        AA -> 27
        AB -> 28

    The important difference from normal base conversion is that
    there is no digit representing 0.

    Therefore, before taking the remainder, we subtract 1 from
    `columnNumber`.

        columnNumber--

    Then:
        remainder = columnNumber % 26

    gives a value from 0 to 25, which maps directly to:

        0 -> A
        1 -> B
        ...
        25 -> Z

    After finding the current character, divide by 26 to move to
    the next position.

    Approach:
    ----------
    1. While `columnNumber > 0`:
        - Decrement it by 1.
        - Find the remainder modulo 26.
        - Convert the remainder to a character.
        - Divide the number by 26.
    2. The characters are generated from right to left, so reverse
       the answer before returning it.

    Example:
        columnNumber = 28

        28 - 1 = 27
        27 % 26 = 1 -> B
        27 / 26 = 1

        1 - 1 = 0
        0 % 26 = 0 -> A

        Result generated = "BA"
        Reverse -> "AB"

    Time Complexity:
    O(log26(n))

    Space Complexity:
    O(log26(n))
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";

        while(columnNumber>0)
        {
            columnNumber--;
            int rem=columnNumber%26;
            ans+='A'+rem;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
