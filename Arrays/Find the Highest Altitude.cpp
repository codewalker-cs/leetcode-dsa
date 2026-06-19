/*
    LeetCode 1732 - Find the Highest Altitude

    Intuition:
    - We start at altitude 0.
    - Each value in 'gain' represents the change in altitude
      between two points.
    - Keep a running sum (current altitude).
    - Track the maximum altitude reached during the journey.

    Example:
    gain = [-5, 1, 5, 0, -7]

    Altitudes:
    0 -> -5 -> -4 -> 1 -> 1 -> -6

    Highest altitude = 1

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for (int altitudeChange : gain) {
            currentAltitude += altitudeChange;
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};
