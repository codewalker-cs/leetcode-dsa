/*
    Problem: Car Fleet
    Platform: LeetCode

    Intuition:
    - A car can never overtake another car in front of it.
    - Compute the time each car takes to reach the target.
    - Sort cars by their position.
    - Traverse from the car closest to the target towards the farthest.
    - If a car takes more time than the fleet ahead, it cannot catch up
      and forms a new fleet.
    - Otherwise, it joins the fleet ahead.

    Time Complexity: O(n log n)
    - Sorting the cars dominates the complexity.

    Space Complexity: O(n)
    - Extra vector to store (position, time) pairs.
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> a;
        int n=position.size();

        for(int i=0;i<n;i++)
        {
            double time=(double)(target-position[i])/speed[i];
            a.push_back({position[i],time});
        }
        sort(a.begin(),a.end());
        int fleet=0;
        double mxtime=0;

        for(int i=n-1;i>=0;i--)
        {
            if(mxtime<a[i].second)
            {
                fleet++;
                mxtime=a[i].second;
            }
        }
        return fleet;
    }
};
