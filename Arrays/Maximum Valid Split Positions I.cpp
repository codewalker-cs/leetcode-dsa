/*
    Intuition:
    We can remove at most one element from nums.

    For every possible removed index (including -1, meaning no
    element is removed), we construct the remaining array and
    calculate the number of valid split positions.

    A split is valid when:
        gcd(left part) == gcd(right part)

    Approach:
    1. Try removing every possible element.
    2. Also try the case where no element is removed.
    3. Build prefix GCD and suffix GCD arrays for the remaining array.
    4. For every split position, compare:
           prefix[i] == suffix[i + 1]
    5. Keep the maximum number of valid splits.

    Time Complexity:
    O(n^2 log(max(nums)))

    Space Complexity:
    O(n)
*/

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int r=-1;r<n;r++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                if(i!=r)
                {
                    temp.push_back(nums[i]);
                }
            }
            int m=temp.size();
            vector<int> pre(m),suff(m);

            pre[0]=temp[0];
            for(int i=1;i<m;i++)
            {
                pre[i]=gcd(pre[i-1],temp[i]);
            }

            suff[m-1]=temp[m-1];
            for(int i=m-2;i>=0;i--)
            {
                suff[i]=gcd(suff[i+1],temp[i]);
            }

            int tempans=0;
            for(int i=0;i<m-1;i++)
            {
                if(pre[i]==suff[i+1]) tempans++;
            }
            ans=max(tempans,ans);
        }
        return ans;
    }
};
