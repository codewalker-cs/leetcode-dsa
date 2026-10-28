/*
Intuition:
- A perfect number is equal to the sum of its positive divisors,
  excluding itself.
- Every number has 1 as a proper divisor, so initialize sum = 1.
- Divisors occur in pairs: if i divides num, then num / i is also
  a divisor.
- Check divisors only up to sqrt(num) to avoid unnecessary iterations.

Approach:
1. If num <= 1, return false.
2. Initialize sum = 1.
3. Iterate i from 2 while i * i <= num:
   - If num % i == 0, add i to sum.
   - If i * i != num, also add num / i to avoid missing its paired divisor.
4. Return whether sum == num.

Time Complexity: O(sqrt(num))
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1) return false;
        int sum=1;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                if(i*i==num)
                {
                    sum+=i;
                }
                else
                {
                    sum+=i+(num/i);
                }
            }
        }
        return sum==num;
    }
};
