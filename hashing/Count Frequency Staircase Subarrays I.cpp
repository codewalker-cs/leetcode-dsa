/*
Intuition:
- A frequency staircase requires the first distinct element to occur
  once, the second distinct element twice, and so on.
- Maintain a frequency map and an order vector for each starting index.
- Whenever we extend a subarray, update the frequency of the new element.
- Check whether every distinct element's frequency matches its
  1-based position in the order vector.

Approach:
1. Fix the starting index i.
2. Initialize a frequency map and an order vector.
3. Extend the subarray by moving j from i to n - 1.
4. If nums[j] appears for the first time, append it to order.
5. Increment its frequency.
6. Check whether freq[order[r]] == r + 1 for every distinct element.
7. If the condition holds, increment the answer.

Time Complexity: O(n^3 * d) in the worst case, where d is the number
of distinct elements in a subarray. More precisely, O(n^3) for
validation plus O(n^2) expected map operations.
Space Complexity: O(n)
*/

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> freq;
            vector<int> order;
            for(int j=i;j<n;j++)
            {
                int x=nums[j];
                if(freq[x]==0)
                {
                    order.push_back(x);
                }

                freq[x]++;
                bool valid=true;
                for(int r=0;r<order.size();r++)
                {
                    if(freq[order[r]]!=r+1)
                    {
                        valid=false;
                        break;
                    }
                }

                if(valid) ans++;
            }
        }
        return ans;
    }
};
