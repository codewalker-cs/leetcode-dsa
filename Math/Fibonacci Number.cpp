/*
 * Problem: Fibonacci Number
 *
 * ------------------------------------------------------------
 * Intuition 1: Recursive Thinking (Brute Force)
 * ------------------------------------------------------------
 * The Fibonacci sequence is defined as:
 *   F(0) = 0
 *   F(1) = 1
 *   F(n) = F(n-1) + F(n-2)
 *
 * Idea:
 *  - Break the problem into smaller subproblems
 *  - Compute fib(n-1) and fib(n-2)
 *  - Add the results
 *
 * Problem with this approach:
 *  - A lot of repeated calculations happen
 *  - Example: fib(5) recomputes fib(3), fib(2) multiple times
 *
 * Time Complexity: O(2^n) (very slow)
 *
 *
 * ------------------------------------------------------------
 * Intuition 2: Iterative DP (Optimized)
 * ------------------------------------------------------------
 * Observation:
 *  - Each Fibonacci number depends only on the previous two values
 *
 * So instead of recomputing:
 *  - Store only last two values
 *  - Build the answer from bottom-up
 *
 * Idea:
 *  - Start from F(0) = 0 and F(1) = 1
 *  - Iteratively compute next values
 *
 * Why this works:
 *  - Eliminates repeated work
 *  - Uses constant space
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        
        // return fib(n-1)+fib(n-2);
        int n2=0,n1=1;
        for(int i=2;i<=n;i++)
        {
            int curr=n1+n2;
            n2=n1;
            n1=curr;
        }
        return n1;
    }
};
