/*
Problem: Difference of Sums

Given two integers n and m:

1. Let num1 be the sum of integers from 1 to n that are NOT divisible by m.
2. Let num2 be the sum of integers from 1 to n that ARE divisible by m.

Return num1 - num2.


-----------------------------------
INTUITION 1 (Brute Force Simulation)
-----------------------------------

We iterate from 1 to n and classify each number:

- If the number is divisible by m → add it to sumDiv
- Otherwise → add it to sumNonDiv

Finally return:
    sumNonDiv - sumDiv

Example:
n = 10, m = 3

Numbers:
1 2 3 4 5 6 7 8 9 10

Divisible by 3 → 3 + 6 + 9 = 18
Not divisible → 1+2+4+5+7+8+10 = 37

Answer:
37 - 18 = 19

Time Complexity: O(n)
Space Complexity: O(1)


-----------------------------------
INTUITION 2 (Mathematical Optimization)
-----------------------------------

Instead of iterating, we use formulas.

Sum of first n numbers:
    total = n(n+1)/2

Numbers divisible by m:
    m, 2m, 3m, ... , km

Where:
    k = n/m

Sum of these numbers:
    m * (1 + 2 + ... + k)

Using formula:
    1+2+...+k = k(k+1)/2

So:
    sumDiv = m * (k(k+1)/2)

Now:
    total = sumNonDiv + sumDiv

We want:
    sumNonDiv - sumDiv

Substitute:
    (total - sumDiv) - sumDiv

Result:
    total - 2*sumDiv

Time Complexity: O(1)
Space Complexity: O(1)
*/


class Solution {
public:
    int differenceOfSums(int n, int m) {
        // int n1=0,n2=0;
        // for(int i=1;i<=n;i++)
        // {
        //     if(i%m==0)
        //     {
        //         n1+=i;
        //     }
        //     else
        //     {
        //         n2+=i;
        //     }
        // }
        // return n2-n1;

        int total = n*(n+1)/2;
        int k = n/m;
        int divSum = m*(k*(k+1)/2);
        return total - 2*divSum;
    }
};
