/*
    Intuition:
    ------------
    Two intervals [l1, r1] and [l2, r2] intersect if:

        l1 <= r2 && l2 <= r1

    Instead of directly counting intersecting pairs, it is easier
    to count the pairs that do NOT intersect.

    After sorting the intervals by their starting points, consider
    interval i = [l, r].

    Since intervals are processed by increasing starting point,
    any earlier interval that does not intersect interval i must
    satisfy:

        end < l

    We store all interval ending points in a sorted array.

    Using lower_bound(ends, l), we can find how many ending points
    are strictly smaller than l.

    Therefore, for every interval, this gives the number of previous
    intervals that do not intersect it.

    Finally:

        intersecting pairs
        = total pairs - non-intersecting pairs

    Total number of pairs is:

        n * (n - 1) / 2

    Approach:
    ----------
    1. Sort intervals by their starting point.
    2. Store all ending points in a separate sorted array.
    3. For every interval:
        - Use lower_bound() to count endpoints strictly smaller
          than its starting point.
        - Add this count to `ans`.
    4. `ans` represents the number of non-intersecting pairs.
    5. Subtract it from the total number of pairs.

    Time Complexity:
    O(n log n)

    Sorting takes O(n log n), and each lower_bound takes O(log n).

    Space Complexity:
    O(n)

    The `ends` array requires O(n) additional space.
*/

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<int> ends;
        for(auto &i:intervals) ends.push_back(i[1]);
        sort(ends.begin(),ends.end());

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=lower_bound(ends.begin(),ends.end(),intervals[i][0])-ends.begin();
        }
        long long total=1LL*n*(n-1)/2;
        return total-ans;
    }
};
