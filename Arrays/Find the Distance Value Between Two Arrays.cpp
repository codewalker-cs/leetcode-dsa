/*
Intuition:
An element in arr1 is counted only if its absolute difference
with every element in arr2 is greater than d.

Approach:
1. Traverse each element of arr1.
2. Check its difference with every element of arr2.
3. If any difference is <= d, mark it invalid.
4. Otherwise, increment the answer.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(int i=0;i<arr1.size();i++)
        {
            bool valid=true;
            for(int j=0;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    valid=false;
                    break;
                }
            }
            if(valid) ans++;
        }
        return ans;
    }
};
