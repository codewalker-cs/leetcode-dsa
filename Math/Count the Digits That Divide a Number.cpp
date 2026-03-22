/*
Intuition:
We iterate through each digit of the number.
For every digit, we check whether it divides the original number.

Important edge case:
- If digit == 0 → skip it (division by zero is undefined)

Time Complexity: O(d)  where d = number of digits
Space Complexity: O(1)
*/

class Solution {
public:
    int countDigits(int num) {
        int count=0,temp=num;
        while(temp>0)
        {
            int t=temp%10;
            temp/=10;

            if(t!=0 && num%t==0)
            {
                count++;
            }
        }
        return count;
    }
};
