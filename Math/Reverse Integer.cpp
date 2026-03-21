/*
Intuition:
We reverse the digits of the number by repeatedly taking the last digit
(using modulo 10) and appending it to the result.

Steps:
1. Extract last digit: x % 10
2. Add it to result: result = result * 10 + digit
3. Remove last digit: x = x / 10

Edge Case:
We must handle overflow (32-bit signed integer range).
If result exceeds INT_MAX or INT_MIN, return 0.
*/

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        
        while(x != 0)
        {
            int digit = x % 10;
            result = result * 10 + digit;
            
            if(result > INT_MAX || result < INT_MIN)
            {
                return 0;
            }
            x /= 10;
        }
        
        return (int)result;
    }
};
