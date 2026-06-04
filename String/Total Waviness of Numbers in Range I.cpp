/*
Intuition:
- The waviness of a number is the total count of peaks and valleys.
- A digit at position i (excluding the first and last digits) is:
    1. A peak  if digit[i] > digit[i - 1] and digit[i] > digit[i + 1]
    2. A valley if digit[i] < digit[i - 1] and digit[i] < digit[i + 1]
- For each number in the range [num1, num2]:
    1. Convert it to a string.
    2. Check every middle digit.
    3. Count how many positions are peaks or valleys.
- Sum the waviness values of all numbers in the range.

Time Complexity:
- Let D be the maximum number of digits in a number.
- check() takes O(D).
- We process (num2 - num1 + 1) numbers.
- Overall: O((num2 - num1 + 1) * D)

Space Complexity:
- O(D) for the string representation.
*/

class Solution {
public:
    int check(int nu)
    {
        string s=to_string(nu);
        int n=s.size();

        int a=0;
        for(int i=1;i<n-1;i++)
        {
            if((s[i-1]-'0')<(s[i]-'0') && (s[i+1]-'0')<(s[i]-'0') || (s[i-1]-'0')>(s[i]-'0') && (s[i+1]-'0')>(s[i]-'0')) a++;
        }

        return a;
    }

    int totalWaviness(int num1, int num2) {
        int ans=0;

        for(int i=num1;i<=num2;i++)
        {
            ans+=check(i);
        }

        return ans;
    }
};
