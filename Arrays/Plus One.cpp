/*
Intuition:
We simulate the manual addition process.

Starting from the last digit:
1. If the digit is 9, it becomes 0 (carry forward).
2. If the digit is not 9, simply increase it by 1 and return.
3. If all digits were 9 (example: 999), we convert them to 000
   and insert 1 at the beginning.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        bool flag=false;
        while(n>=0 && digits[n]==9)
        {
            digits[n]=0;
            flag=true;
            n--;
        }
        if(flag==true && n==-1)
        {
            digits.insert(digits.begin(),1);
        }
        else
        {
            digits[n]++;
        }
        return digits;
    }
};
