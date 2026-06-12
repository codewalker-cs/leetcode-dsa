/*
Intuition:
A Roman numeral is normally evaluated from left to right.

Most symbols contribute their value directly:
VI = 5 + 1 = 6

However, when a smaller value appears before a larger value,
it represents subtraction:
IV = 5 - 1 = 4
IX = 10 - 1 = 9

Observation:
For every character except the last:
- If its value is smaller than the next character's value,
  subtract it from the answer.
- Otherwise, add it to the answer.

The last character is always added because there is no
next character to compare against.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }

        return result + roman[s.back()];
    }
};
