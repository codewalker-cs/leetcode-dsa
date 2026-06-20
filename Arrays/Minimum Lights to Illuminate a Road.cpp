/*
    Problem: Minimum Lights

    Intuition:
    -----------
    Each light at index i with power p illuminates the range:
        [i - p, i + p]

    We use a difference array to mark all illuminated positions efficiently.

    After processing all lights:
    - Compute prefix sums.
    - Any position with coverage = 0 is a dark position.

    Observation:
    ------------
    One additional light can illuminate at most 3 consecutive positions
    (itself and one position on each side).

    Therefore, after collecting all dark positions, we greedily place a
    new light at (dark_position + 1), which covers:
        [dark_position, dark_position + 2]

    Then skip every dark position already covered.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> dif(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(lights[i]!=0)
            {
                int m=max(0,i-lights[i]);
                dif[m]++;
                m=min(n-1,i+lights[i]);
                dif[m+1]--;
            }
        }

        vector<int> inv;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cur+=dif[i];
            if(cur==0) inv.push_back(i);
        }

        int m=inv.size(),ans=0;

        for(int i=0;i<m;)
        {
            int l=inv[i];
            int reach=l+2;
            ans++;
            while(i<m && inv[i]<=reach)
            {
                i++;
            }
        }

        return ans;
    }
};
