/*
    Intuition:
    We use the maximum light duration as the limiting value.

    For each arrival time:
    - Calculate its position inside the current period using i % period.
    - If this position is already beyond the maximum light duration,
      calculate how long we need to wait until the next period.
    - Keep track of the maximum waiting time.

    Example:
        period = 10
        mx = 6
        arrivalTime = [2, 7]

        For 2:
            r = 2
            r < mx, so no wait.

        For 7:
            r = 7
            r >= mx
            wait = 10 - 7 = 3

        Answer = 3

    Time Complexity:
        O(n)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx=*max_element(lights.begin(),lights.end());
        int ans=0;

        for(int &i:arrivalTime)
        {
            int r=i%period;
            if(r>=mx) ans=max(ans,period-r);
        }
        return ans;
        
        // int n=arrivalTime.size(),m=lights.size();
        // int ans=0;

        // for(int i=0;i<n;i++)
        // {
        //     int t=arrivalTime[i];
        //     int r=t%period,tempans=INT_MAX;
            
        //     for(int j=0;j<m;j++)
        //     {
        //         if(r<lights[j])
        //         {
        //             tempans=0;
        //         }
        //         else
        //         {
        //             tempans=min(tempans,period-r);
        //         }
        //     }
        //     ans=max(ans,tempans);
        // }
        // return ans;
    }
};
