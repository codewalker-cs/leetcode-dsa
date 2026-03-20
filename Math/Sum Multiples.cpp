/*
    Problem: Sum of Multiples

    Intuition:
    ----------
    We need to find the sum of all numbers from 1 to n that are divisible by
    3, 5, or 7.

    Instead of storing numbers in a vector (which uses extra space),
    we can directly accumulate the sum while iterating.

    Key Idea:
    ----------
    - Traverse from 1 to n
    - Check if number is divisible by 3 OR 5 OR 7
    - If yes, add it to the sum

    This avoids unnecessary space usage and keeps the solution efficient.

    Time Complexity:
    ----------------
    O(n) → We iterate through all numbers from 1 to n

    Space Complexity:
    -----------------
    O(1) → No extra space used

    Example:
    --------
    Input: n = 10
    Multiples: 3, 5, 6, 7, 9, 10
    Output: 40
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if((i%3==0) || (i%5==0) || (i%7==0))
            {
                sum+=i;
            }
        }
        return sum;
    }
};
