/*
Intuition:
We want to convert all uppercase letters in a string to lowercase.
In ASCII, uppercase letters ('A' to 'Z') lie in a continuous range.
Instead of manually adding 32 to convert characters, we use the
standard library function `tolower()` from <cctype>, which safely
handles the conversion and improves code readability.

We iterate through each character by reference so we can modify
the string in place without extra memory.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <cctype>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(char &c : s)
        {
            if(c>=65 && c<=90)
            {
                //c=c+32;
                c=tolower(c);
            }
        }
        return s;
    }
};
