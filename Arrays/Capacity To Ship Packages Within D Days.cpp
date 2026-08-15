/*
    Intuition:
    We need to find the minimum ship capacity that allows all packages
    to be shipped within the given number of days.

    The answer lies between:
    - l = maximum weight of any single package
      because the ship must be able to carry the heaviest package.
    - r = sum of all weights
      because in the worst case, we could ship everything in one day.

    We can binary search this range.

    For each capacity mid, simulate the shipping process:
    - Start with day = 1 and current load = 0.
    - Keep adding packages to the current day.
    - If adding a package exceeds mid, start a new day.
    - Count how many days are required.

    If the required days are greater than the allowed days,
    mid is too small, so increase the capacity.

    Otherwise, mid is a valid capacity, so try finding a smaller one.

    Example:
    weights = [1,2,3,4,5,6,7,8,9,10], days = 5

    Search range:
    l = 10, r = 55

    Suppose mid = 32.
    We can divide the packages into days without exceeding 32,
    so 32 is a valid capacity.

    We continue searching for a smaller valid capacity.

    The binary search finally returns the minimum possible capacity.

    Time Complexity:
    O(n * log(sum(weights)))

    Space Complexity:
    O(1)
    */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int r=0,l=INT_MIN;
        for(int &i:weights)
        {
            l=max(l,i);
            r+=i;
        }

        while(l<r)
        {
            int mid=l+(r-l)/2;
            int d=1,s=0;
            for(int &i:weights)
            {
                s+=i;
                if(s>mid)
                {
                    d++;
                    s=i;
                }
            }

            if(d>days)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
