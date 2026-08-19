/*
    Intuition:
    ------------
    For every index i, we can calculate how many positive integers
    are missing before arr[i].

    Since the array is strictly increasing:

        missing = arr[i] - i - 1

    Example:
        arr = [2, 3, 4, 7, 11]

        i = 0 -> missing = 2 - 0 - 1 = 1
        i = 1 -> missing = 3 - 1 - 1 = 1
        i = 2 -> missing = 4 - 2 - 1 = 1
        i = 3 -> missing = 7 - 3 - 1 = 3
        i = 4 -> missing = 11 - 4 - 1 = 6

    The number of missing values is non-decreasing, so we can
    binary search for the first index where:

        missing >= k

    After the binary search:
        r = last index where missing < k

    All elements up to index r are already accounted for.
    Therefore, the kth missing number is:

        k + r + 1

    Example:
        arr = [2, 3, 4, 7, 11], k = 5

        Binary search finds:
            r = 3

        Answer:
            5 + 3 + 1 = 9

    Time Complexity:
    ----------------
    O(log n)

    Space Complexity:
    -----------------
    O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            int miss=arr[m]-m-1;

            if(miss<k)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return k+r+1;
    }
};
