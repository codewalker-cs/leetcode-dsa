/*
    Problem: Minimum Number of Days to Make m Bouquets

    Intuition:
    We need to find the minimum day such that we can make at least
    m bouquets, where each bouquet requires k adjacent flowers.

    Instead of checking every possible day, we use Binary Search on
    the answer.

    For a given day `mid`:
    - If bloomDay[i] <= mid, the flower has bloomed.
    - We count consecutive bloomed flowers.
    - Whenever we get k consecutive flowers, we form one bouquet.
    - If we can make m bouquets, `mid` is a possible answer.

    Binary Search:
    The days have a monotonic property:

        Day:       1  2  3  4  5  6  7
        Possible:  N  N  N  N  Y  Y  Y
                              ^
                            Answer

    If we can make m bouquets on day `mid`, we try an earlier day:
        r = mid - 1

    Otherwise, we need more days:
        l = mid + 1

    Example:
        bloomDay = [1,10,3,10,2]
        m = 3
        k = 1

        By day 3:
        [✓, ✗, ✓, ✗, ✓]

        We can make 3 bouquets, so answer = 3.

    Important:
    If m * k > n, it is impossible to make m bouquets because
    we don't have enough flowers.

    We use `long long` for m * k to avoid integer overflow.

    Time Complexity:
        O(n * log(maxDay))

        Binary search performs O(log(maxDay)) checks,
        and each check scans the array in O(n).

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;

        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        // int ans=INT_MAX;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int c=0,adj=k;
            for(int &i:bloomDay)
            {
                if(i<=mid)
                {
                    adj--;
                    if(adj==0)
                    {
                        adj=k;
                        c++;
                    }
                }
                else
                {
                    if(adj<k)
                    {
                        adj=k;
                    }
                }

                if(c==m)
                {
                    // ans=min(ans,mid);
                    break;
                }
            }

            if(c>=m)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return l;
    }
};
