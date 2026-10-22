/*
Intuition:
- The element sum is the sum of all numbers in the array.
- The digit sum is the sum of every digit in every number.
- Calculate both sums and return their absolute difference.

Approach:
1. Initialize element sum (es) and digit sum (ds) to 0.
2. Traverse each number in the array:
   - Add the number to es.
   - Extract its digits using num % 10 and add them to ds.
   - Remove the last digit using num /= 10.
3. Return abs(es - ds).

Time Complexity: O(n * d), where n is the array size and d is the maximum number of digits in an element.
Space Complexity: O(1)
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int es=0,ds=0;

        for(int num : nums)
        {
            es+=num;
            while(num>0)
            {
                ds+=num%10;
                num/=10;
            }
        }
        return abs(es-ds);
    }
};
