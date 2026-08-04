/*
    Intuition 1: Sort + Explicit Pair Array

    Since intervals can be given in any order, we first sort them by their
    starting point. This guarantees that if two intervals overlap, they
    will appear consecutively.

    We copy the intervals into a vector<pair<int,int>> for easier handling.
    Then, we iterate through the sorted intervals.

    - Start a new merged interval.
    - Keep merging subsequent intervals as long as they overlap with the
      current merged interval.
    - The merged interval's end is updated to the maximum ending point seen.
    - Once there is no overlap, store the merged interval and continue.

    Example:
    Intervals:
    [1,3] [2,6] [8,10] [15,18]

    After sorting:
    [1,3] [2,6] [8,10] [15,18]

    Start with:
    ans = [1,3]

    [2,6] overlaps
    -> ans = [1,6]

    [8,10] does not overlap
    -> store new interval

    Final Answer:
    [1,6] [8,10] [15,18]

    Time Complexity : O(n log n)
        - Sorting takes O(n log n)
        - Merging takes O(n)

    Space Complexity : O(n)
        - Extra vector<pair<int,int>> is used.
*/


/*
    Intuition 2: Sort + Greedy (Optimized)

    We can avoid creating another vector<pair<int,int>>.

    Sort the original intervals directly.

    Maintain the answer vector itself as the list of merged intervals.

    For every interval:

    1. If the answer is empty, or the current interval starts after the
       last merged interval ends, they do not overlap.
       Push it as a new interval.

    2. Otherwise, they overlap.
       Extend the end of the last merged interval using the maximum end.

    Example:
    [1,3] [2,6] [8,10] [15,18]

    ans = []

    [1,3]
    -> ans = [1,3]

    [2,6]
    overlaps
    -> ans = [1,6]

    [8,10]
    no overlap
    -> ans = [1,6] [8,10]

    [15,18]
    no overlap
    -> ans = [1,6] [8,10] [15,18]

    Time Complexity : O(n log n)
        - Sorting dominates.

    Space Complexity : O(1) Extra Space
        - No additional data structures are used apart from the output vector.
        - (Ignoring the returned answer vector as is standard in interviews.)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> in;
        int n=intervals.size();

        for(int i=0;i<n;i++)
        {
            in.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(in.begin(),in.end());
        int j=0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back({in[i].first,in[i].second});
            
            while(i<n-1 && ans[j][1]>=in[i+1].first)
            {
                ans[j][1]=max(in[i+1].second,ans[j][1]);
                i++;
            }
            j++;
        }
        return ans;

        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> ans;

        // for(auto &x : intervals)
        // {
        //     if(ans.empty() || ans.back()[1] < x[0])
        //         ans.push_back(x);
        //     else
        //         ans.back()[1] = max(ans.back()[1], x[1]);
        // }
        // return ans;
    }
};
