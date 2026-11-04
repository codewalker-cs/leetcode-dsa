/*
Intuition:
- We need to replace every dot (.) in the IP address with "[.]".
- All other characters remain unchanged.
- Build a new string by traversing the original address.

Approach:
1. Initialize an empty result string.
2. Traverse each character in the address.
3. If the character is '.', append "[.]" to the result.
4. Otherwise, append the character directly.
5. Return the resulting string.

Time Complexity: O(n), where n is the length of the address.
Space Complexity: O(n), for the resulting string.
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";

        for (char c : address) {
            if (c == '.') {
                ans += "[.]";
            } else {
                ans += c;
            }
        }

        return ans;
    }
};
