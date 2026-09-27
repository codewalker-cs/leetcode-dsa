/*
    Intuition:
    ------------
    We want to rearrange the array in increasing order.

    Instead of sorting the array directly, we count how many times
    each value occurs using a frequency array.

    Then we scan the frequency array from smallest to largest and
    add each value to the answer as many times as it occurs.

    Since each complete scan adds at least one remaining element,
    the process continues until all elements are placed.

    Approach:
    ----------
    1. Create a frequency array for all possible values.
    2. Count the occurrences of every number.
    3. Repeatedly scan from 0 to 100.
    4. Whenever a number has a remaining frequency, add it to `ans`
       and decrease its frequency.
    5. Stop when all elements have been added.

    Time Complexity:
    O(n * k)

    where k is the range of possible values.
    Since k = 101 here, this is effectively O(n).

    Space Complexity:
    O(n + k)

    `ans` requires O(n) space and the frequency array requires O(k).
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }

        vector<int> ans;
        while(ans.size()<nums.size())
        {
            for(int i=0;i<101;i++)
            {
                if(freq[i]>0)
                {
                    ans.push_back(i);
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};
