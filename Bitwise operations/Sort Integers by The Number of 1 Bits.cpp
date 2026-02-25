/*
------------------------------------------------------------
Problem: Sort Integers by The Number of 1 Bits

Intuition:
We need to sort the array based on two conditions:
1) Primary Condition:
   Sort numbers in ascending order by the count of 1s 
   in their binary representation.

2) Secondary Condition (Tie Breaker):
   If two numbers have the same number of 1s,
   sort them in ascending numerical order.

Approach:
- Use C++ STL sort() with a custom comparator.
- Use GCC built-in function __builtin_popcount()
  to efficiently count the number of set bits.
- Comparator first compares set-bit count.
- If equal, compare actual values.

Example:
Input  : [0,1,2,3,4,5,6,7,8]
Output : [0,1,2,4,8,3,5,6,7]

Time Complexity:
O(n log n)  -> due to sorting

Space Complexity:
O(1)        -> ignoring sorting stack space

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(int a,int b)
    {
        int c1=__builtin_popcount(a);
        int c2=__builtin_popcount(b);

        if(c1==c2)
        {
            return a<b;
        }

        return c1<c2;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};
