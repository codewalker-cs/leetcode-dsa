/*
Intuition
---------
We are given versions from 1 to n.

The versions follow a monotonic pattern:

Good Good Good ... Good Bad Bad Bad ... Bad

This pattern allows us to use Binary Search.

Let mid be the middle version:

1. If mid is bad:
   - The first bad version can be mid itself or somewhere before it.
   - Therefore, we keep mid in the search space by setting:
       r = mid

2. If mid is good:
   - The first bad version must be after mid.
   - Therefore:
       l = mid + 1

We continue shrinking the search space until l == r.
At that point, only one candidate remains, which must be the
first bad version.

Why use:
    mid = l + (r - l) / 2
instead of:
    mid = (l + r) / 2

To avoid integer overflow when l and r are large.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+((r-l)/2);

            if(isBadVersion(mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
