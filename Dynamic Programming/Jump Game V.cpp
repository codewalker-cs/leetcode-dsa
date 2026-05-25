/*
    Jump Game V

    Problem:
    Given an array arr and an integer d, you can jump from index i to:

        - any index j on the left
        - any index j on the right

    such that:

        1. |i - j| <= d
        2. arr[j] < arr[i]
        3. every element between i and j is smaller than arr[i]

    Return the maximum number of indices that can be visited.

    ------------------------------------------------------------

    Intuition

    From an index i, we are only allowed to jump to smaller values.

    This naturally forms a Directed Acyclic Graph (DAG):

        larger value  --->  smaller value

    Since transitions only go from larger to smaller values,
    we can process indices in increasing order of their values.

    Let:

        dp[i] = maximum jumps starting from index i

    Initially:

        dp[i] = 1

    because we can always stay at the current index.

    For every index:
        - explore left up to distance d
        - explore right up to distance d
        - stop when a greater/equal element blocks the path

    Transition:

        dp[i] = max(dp[i], 1 + dp[j])

    ------------------------------------------------------------

    Time Complexity:

        O(N * D)

    Space Complexity:

        O(N)
*/

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> t(n+1,-1);
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        
        sort(v.begin(), v.end());

        for(auto &x : v)
        {
            int val=x.first,idx=x.second;
            int result=1;

            //left
            for(int j=idx-1;j>=max(0,idx-d);j--)
            {
                if(arr[j]>=arr[idx]) break;

                result=max(result,1+t[j]);
            }

            //right
            for(int j=idx+1;j<=min(n-1,idx+d);j++)
            {
                if(arr[j]>=arr[idx]) break;
                
                result=max(result,1+t[j]);
            }

            t[idx]=result;
        }

        int ans=1;

        for(int i=0;i<n;i++)
        {
            ans=max(ans,t[i]);
        }

        return ans;
    }
};
