/*
Intuition:
This problem asks us to repeatedly add the digits of a number until
only one digit remains.

Example:
38 -> 3+8 = 11
11 -> 1+1 = 2

Instead of repeatedly summing digits, we use the Digital Root property.

Observation:
Numbers follow a repeating pattern modulo 9.

Digital Root Formula:
if num == 0 -> return 0
else -> return 1 + (num - 1) % 9

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
