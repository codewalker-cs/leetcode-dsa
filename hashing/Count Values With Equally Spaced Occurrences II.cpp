/*
    Intuition:
    ------------
    For every distinct number, we store all the indices where it
    appears in the array.

    A number is considered special if:
        1. It appears at least 3 times.
        2. Its occurrence indices form an arithmetic progression.

    For example:
        nums = [5, 2, 5, 7, 5, 9, 5]

        Indices of 5 = [0, 2, 4, 6]

        Differences:
            2 - 0 = 2
            4 - 2 = 2
            6 - 4 = 2

        Since all differences are equal, 5 is special.

    We only need to compare consecutive occurrence indices.

    Approach:
    ----------
    1. Store the indices of every distinct number using a hash map.
    2. For each number:
        - If it appears fewer than 3 times, it cannot be special.
        - Calculate the difference between its first two occurrences.
        - Check whether every consecutive pair has the same difference.
    3. If all differences are equal, increment the answer.

    Time Complexity:
    O(n)

    Every index is inserted once and every stored index is checked
    at most once.

    Space Complexity:
    O(n)

    In the worst case, all indices are stored in the hash map.
*/

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> freq;

        for(int i=0;i<n;i++)
        {
            freq[nums[i]].push_back(i);
        }

        int ans=0;
        for(auto q:freq)
        {
            if(q.second.size()>=3)
            {
                int diff=q.second[1]-q.second[0];
                bool y=true;
                for(int i=2;i<q.second.size();i++)
                {
                    if(q.second[i]-q.second[i-1]!=diff)
                    {
                        y=false;
                        break;
                    }
                }
                if(y) ans++;
            }
        }
        return ans;
    }
};
