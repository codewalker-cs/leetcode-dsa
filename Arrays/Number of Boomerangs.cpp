/*
    Intuition:
    ------------
    A boomerang is an ordered tuple (i, j, k) such that:

        distance(i, j) == distance(i, k)

    For every point `i`, we can treat it as the center point.

    We calculate the squared distance from `i` to every other point:

        distance² = (x1 - x2)² + (y1 - y2)²

    We use squared distance instead of actual distance because taking
    the square root is unnecessary.

    Suppose a particular distance occurs `freq` times from point `i`.

    We need to choose two different points `j` and `k` at this distance.

    Since the order matters:

        (i, j, k)
        (i, k, j)

    are two different boomerangs.

    Therefore, `freq` points give:

        freq * (freq - 1)

    boomerangs.

    Approach:
    ----------
    1. Treat every point `i` as the center of the boomerang.
    2. Calculate the squared distance from `i` to every other point.
    3. Store the frequency of each distance in a hash map.
    4. For every distance occurring `freq` times, add:
           freq * (freq - 1)
    5. Repeat for every point.

    Time Complexity:
    O(n²)

    We calculate the distance between every pair of points.

    Space Complexity:
    O(n)

    The frequency map can contain up to O(n) different distances
    for one center point.
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                int dis=(dx*dx)+(dy*dy);
                mp[dis]++;
            }
            
            for(auto &[d,c]:mp)
            {
                ans+=c*(c-1);
            }
        }
        return ans;
    }
};
