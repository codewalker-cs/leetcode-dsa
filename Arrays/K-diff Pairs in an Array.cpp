/*
    Intuition:
    We need to count unique pairs (x, y) such that:
        |x - y| = k

    Instead of checking every pair, store the frequency of each
    distinct number.

    For k > 0:
    For every number x, check whether x + k exists.
    This counts each valid pair exactly once.

    For k == 0:
    We need two occurrences of the same number, so check whether
    its frequency is greater than 1.

    Example:
    nums = [3, 1, 4, 1, 5]
    k = 2

    Frequencies:
    1 -> 2
    3 -> 1
    4 -> 1
    5 -> 1

    Valid pairs:
    (1,3)
    (3,5)

    Answer = 2

    Time Complexity:
    O(n)

    Space Complexity:
    O(n)
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // set<pair<int,int>> ans;
        // int n=nums.size();

        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(abs(nums[i]-nums[j])==k)
        //         {
        //             ans.insert({nums[i],nums[j]});
        //         }
        //     }
        // }
        // return ans.size();

        unordered_map<int,int> tar;
        for(int i:nums)
        {
            tar[i]++;
        }

        int ans=0;
        for(auto i:tar)
        {
            if(k==0)
            {
                if(i.second>1) ans++;
            }
            else if(tar.find(i.first+k)!=tar.end())
            {
                ans++;
            }
        }
        return ans;
    }
};
