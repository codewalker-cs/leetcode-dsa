// Intuition:
// We want to determine whether we can destroy every asteroid.
//
// If our current mass is at least the asteroid's mass, we can destroy it
// and absorb its mass, increasing our own mass.
//
// To maximize our chances of success, we should always destroy the smallest
// available asteroid first. This greedy strategy ensures that we grow as
// quickly as possible before facing larger asteroids.
//
// Therefore:
// 1. Sort the asteroids in non-decreasing order.
// 2. Traverse them from smallest to largest.
// 3. If current mass is smaller than an asteroid, return false.
// 4. Otherwise absorb its mass and continue.
//
// We use long long because the accumulated mass can exceed the range of int.
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) excluding the sorting 

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m=mass;
        int n=asteroids.size();
        
        for(int i=0;i<n;i++)
        {
            if(m>=asteroids[i])
            {
                m+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
