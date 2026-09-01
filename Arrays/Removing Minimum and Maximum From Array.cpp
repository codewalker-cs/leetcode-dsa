/*
    Intuition:

    We need to delete elements from the beginning and/or the end of
    the array so that both the minimum and maximum elements are removed.

    First, find the indices of:
        - The minimum element
        - The maximum element

    Let:
        a = index of the smaller of these two indices
        b = index of the larger of these two indices

    So the minimum and maximum are located at positions `a` and `b`.

    There are three possible ways to remove both elements:

    ---------------------------------------------------------------
    1. Remove everything from the front
    ---------------------------------------------------------------

    If we remove elements from index 0 through `b`, both the minimum
    and maximum will be deleted.

    Number of deletions:

        b + 1

    ---------------------------------------------------------------
    2. Remove everything from the back
    ---------------------------------------------------------------

    If we remove elements from index `a` through the end, both
    elements will be deleted.

    Number of deletions:

        n - a

    ---------------------------------------------------------------
    3. Remove from both sides
    ---------------------------------------------------------------

    We can remove the first `a + 1` elements from the front,
    which removes the element at index `a`.

    Then remove the elements from index `b` to the end,
    which removes the element at index `b`.

    Number of deletions:

        (a + 1) + (n - b)

    ---------------------------------------------------------------

    The answer is simply the minimum of these three possibilities.

    Example:

        nums = [2, 10, 7, 5, 4, 1, 8, 6]

        minimum = 1  -> index 5
        maximum = 10 -> index 1

        a = 1
        b = 5

        Front:
            b + 1 = 6

        Back:
            n - a = 8 - 1 = 7

        Both sides:
            (a + 1) + (n - b)
            = 2 + 3
            = 5

        Answer = 5

    Time Complexity:
        O(n)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int,int> mx={INT_MIN,-1},mi={INT_MAX,-1};
        int n=nums.size();

        if(n<=2) return n;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<=mi.first)
            {
                mi.second=i;
                mi.first=nums[i];
            }

            if(nums[i]>mx.first)
            {
                mx.second=i;
                mx.first=nums[i];
            }
        }

        int a=min(mi.second,mx.second);
        int b=max(mi.second,mx.second);

        int front=b+1;
        int back=n-a;
        int both=(a+1)+(n-b);

        return min({front,back,both});
    }
};
