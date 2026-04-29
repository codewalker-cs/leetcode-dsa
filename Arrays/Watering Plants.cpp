/*
Intuition:
We simulate the process of watering plants from left to right.

- Start at river (position = -1) with full capacity.
- For each plant:
    1. Move to plant → +1 step
    2. If not enough water:
        - Go back to river → i steps
        - Come back → i steps
        - Total extra = 2*i
        - Refill
    3. Water the plant

Key idea:
Only refill when necessary (greedy simulation).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int currWater = capacity;
        for(int i = 0; i < plants.size(); i++)
        {
            if(currWater < plants[i])
            {
                steps += 2 * i;
                currWater = capacity;
            }
            steps += 1;
            currWater -= plants[i];
        }
        return steps;
    }
};
