/*
    ------------------------------------------------------------
    Intuition
    ------------------------------------------------------------
    We maintain the current available resources while processing
    the array from left to right.

    If the current resources are enough to process the current
    element, simply consume those resources.

    Otherwise, we need to perform refill operations.
    Each refill increases the resources by exactly 'k'.

    Instead of simulating every refill one by one (which would
    be too slow when nums[i] is very large), we directly compute
    how many refills are required using ceiling division.

    If 'add' refill operations are performed and 'count' refill
    operations have already been used, then the costs added are

        count + 1,
        count + 2,
        ...
        count + add

    This is an arithmetic progression whose sum is

        (first + last) * number_of_terms / 2

    where
        first = count + 1
        last  = count + add

    We use this formula to compute the refill cost in O(1).

    ------------------------------------------------------------
    Example
    ------------------------------------------------------------
    nums = [5, 7, 8], k = 5

    Initial:
        resources = 5
        refills = 0
        cost = 0

    Process 5:
        resources = 5 >= 5
        resources = 0

    Process 7:
        resources = 0 < 7

        need = 7
        add = ceil(7 / 5) = 2

        Refill costs:
            1 + 2 = 3

        cost = 3
        refills = 2
        resources = 0 + 2 * 5 = 10
        resources -= 7
        resources = 3

    Process 8:
        resources = 3 < 8

        need = 5
        add = 1

        Refill cost:
            3

        Total cost = 6

    ------------------------------------------------------------
    Time Complexity
    ------------------------------------------------------------
    O(n)

    ------------------------------------------------------------
    Space Complexity
    ------------------------------------------------------------
    O(1)
*/

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long mod=1e9+7;
        long long t=k,count=0;
        long long cost=0;

        for(int &i : nums)
        {
            if(t<i)
            {
                long long need=i-t;
                long long add=(need+k-1)/k;
                long long first=count+1;
                long long last=count+add;

                __int128 sum=(__int128)(first+last)*add/2;
                cost=(cost+(long long)(sum%mod))%mod;
                count+=add;
                t+=(k*add);
            }
            t-=i;
        }
        return cost;
    }
};
