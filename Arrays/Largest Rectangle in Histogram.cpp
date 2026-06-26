/*
    Problem: Largest Rectangle in Histogram
    Platform: LeetCode

    Intuition:
    - Maintain a monotonic increasing stack storing {startIndex, height}.
    - For each bar:
        * If its height is greater than or equal to the stack top,
          simply push it.
        * Otherwise, pop all taller bars since the current bar limits
          their maximum width.
        * While popping, calculate the rectangle area using:
              height × (currentIndex - startIndex)
        * Keep track of the earliest index reached by the popped bars,
          then push the current bar with that index.
    - After processing all bars, the remaining bars extend to the end
      of the histogram, so compute their areas separately.

    Time Complexity: O(n)
    - Every bar is pushed and popped at most once.

    Space Complexity: O(n)
    - Monotonic stack storing histogram bars.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        long long area=0;
        stack<pair<int,int>> s;

        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push({i,heights[i]});
            }
            else
            {
                int temp=i;
                while(!s.empty() && s.top().second>heights[i])
                {
                    area=max(area,(long long)(s.top().second*(i-s.top().first)));
                    temp=s.top().first;
                    s.pop();
                }
                s.push({temp,heights[i]});
            }
        }

        while(!s.empty())
        {
            area=area=max(area,(long long)(s.top().second*(n-s.top().first)));
            s.pop();
        }
        return area;
    }
};
