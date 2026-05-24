/*
    Minimum Jumps to Reach End
    --------------------------

    Intuition:
    ----------
    We can think of every index as a node in a graph.

    From index i, we can jump to:
    1. i + 1
    2. i - 1
    3. Any index j where arr[i] == arr[j]

    Since every jump costs exactly 1 step,
    this becomes a shortest path problem in an unweighted graph.

    BFS is the optimal choice because:
    - BFS explores level by level
    - The first time we reach the last index,
      we are guaranteed to have the minimum steps

    Optimization:
    -------------
    To quickly access all indices having the same value,
    we store:

        value -> list of indices

    Important optimization:
    After processing all indices of a value once,
    we erase that value from the hashmap.

    This prevents repeated traversals and reduces
    the complexity from O(n^2) to nearly O(n).

    Time Complexity:
    ----------------
    O(n)

    Space Complexity:
    -----------------
    O(n)
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool> v(n,false);
        unordered_map<int,vector<int>> s;

        for(int i=0;i<arr.size();i++)
        {
            s[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        v[0]=true;
        int steps=0;

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int curr=q.front();
                q.pop();

                int left=curr-1;
                int right=curr+1;

                if(curr==n-1) return steps;

                if(left>=0 && !v[left])
                {
                    q.push(left);
                    v[left]=true;
                }

                if(right<=n-1 && !v[right])
                {
                    q.push(right);
                    v[right]=true;
                }

                for(auto x : s[arr[curr]])
                {
                    if(!v[x])
                    {
                        q.push(x);
                        v[x]=true;
                    }
                }

                s.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};
