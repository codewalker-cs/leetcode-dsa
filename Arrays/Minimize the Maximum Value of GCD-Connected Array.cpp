/*
Intuition:
- First, find the smallest prime factor of value.
- The smallest prime factor determines the minimum possible
  difference needed for the next element.
- Calculate the number of elements on the left and right of index.
- Check whether the available value is sufficient to satisfy
  the left-side constraints.
- If the constraints cannot be satisfied, return -1.
- Otherwise, calculate the minimum possible maximum value
  using the right-side elements.

Approach:
1. If value == 1, return -1.
2. Find the smallest prime factor p of value.
   - If no factor is found, p remains value because value is prime.
3. Calculate:
   - l = index (elements to the left).
   - r = n - index - 1 (elements to the right).
4. If there are elements on the left:
   - For even value, calculate av = value / 2 - 1.
   - For odd value, calculate av = (value - p) / 2.
   - If av < l, return -1.
5. If there are no elements on the right, return value.
6. Otherwise, calculate and return:
   value + p + 2 * (r - 1).

Time Complexity: O(sqrt(value))
Space Complexity: O(1)
*/

class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1) return -1;
        long long p=value;

        for(long long i=2;i*i<=value;i++)
        {
            if(value%i==0)
            {
                p=i;
                break;
            }
        }

        int l=index,r=n-index-1;

        if(l>0)
        {
            long long av;

            if(value%2==0)
            {
                av=value/2-1;
            }
            else
            {
                av=(value-p)/2;
            }

            if(av<l) return -1;
        }

        if(r==0) return value;
        return (long long)value+p+2LL*(r-1);
    }
};
