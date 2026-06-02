/*
Intuition:
We need to complete exactly one land ride and one water ride, in any order.

Consider the order: Ride Type 1 -> Ride Type 2.

For the first ride type, only the earliest possible finishing time matters:
    minFinish = min(start[i] + duration[i])

Once we finish the first ride at minFinish, for every ride of the
second type, we can start it at:

    max(minFinish, startTimeOfSecondRide)

and finish at:

    max(minFinish, startTimeOfSecondRide) + durationOfSecondRide

We compute the minimum finish time for:
    1. Land -> Water
    2. Water -> Land

and return the smaller of the two.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    int calc(vector<int> &s1,vector<int> &e1,vector<int> &s2,vector<int> &e2)
    {
        int t=INT_MAX,n=s1.size(),m=s2.size();

        for(int i=0;i<n;i++)
        {
            t=min(t,s1[i]+e1[i]);
        }

        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,max(t,s2[i])+e2[i]);
        }
        
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(calc(landStartTime,landDuration,waterStartTime,waterDuration),calc(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};
