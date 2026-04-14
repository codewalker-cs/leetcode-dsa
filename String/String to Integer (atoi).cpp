// Intuition:
// This implementation follows the standard approach for converting a string to an integer (atoi).
// 1. Skip leading whitespaces.
// 2. Determine the sign (+ or -).
// 3. Process numeric digits and build the number.
// 4. Handle overflow/underflow during construction.
// 5. Stop parsing when a non-digit character is encountered.
//
// Key Idea:
// Instead of using stoi (which can throw exceptions), we build the number manually
// and clamp it within the 32-bit signed integer range [-2^31, 2^31 - 1].
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        while(i<n && s[i]==' ') i++;

        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-'))
        {
            if(s[i]=='-') sign=-1;
            i++;
        }
        
        long long num=0;
        while(i<n && isdigit(s[i]))
        {
            num=num*10+(s[i]-'0');
            if(sign*num>INT_MAX) return INT_MAX;
            if(sign*num<INT_MIN) return INT_MIN;
            i++;
        }

        return sign*num;
    }
};
