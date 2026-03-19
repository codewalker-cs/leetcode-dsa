/*
Intuition:
-----------
Instead of checking every number from 1 to sqrt(x),
we use Binary Search to efficiently find the answer.

We search in the range [1, x]:
- If mid * mid == x → exact answer
- If mid * mid < x → move right (store answer)
- If mid * mid > x → move left

To avoid overflow:
- Instead of mid * mid <= x
- Use mid <= x / mid

Time Complexity: O(log x)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int low = 1, high = x;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
