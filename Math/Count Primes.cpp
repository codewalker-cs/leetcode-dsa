/*
Intuition:
- We need to count prime numbers strictly less than n.
- Initially, assume every number from 2 to n - 1 is prime.
- Use the Sieve of Eratosthenes to eliminate composite numbers.
- Whenever a number is marked as composite for the first time,
  decrement the prime count.

Approach:
1. If n <= 2, return 0.
2. Initialize cnt = n - 2 because there are n - 2 integers from 2 to n - 1.
3. Create a boolean array s of size n, initialized to true.
4. Iterate i from 2 while i * i < n:
   - If s[i] is true, i is prime.
   - Start marking multiples from i * i because smaller multiples
     have already been handled.
   - Mark each previously unmarked multiple as composite and
     decrement cnt.
5. Return cnt.

Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int cnt=n-2;
        vector<char> s(n,1);

        for(int i=2;i*i<n;i++)
        {
            if(s[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    if(s[j])
                    {
                        s[j]=0;
                        cnt--;
                    }
                }
            }
        }
        return cnt;
    }
};
