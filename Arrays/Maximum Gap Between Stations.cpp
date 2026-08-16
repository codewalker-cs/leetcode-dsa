  /*
        Intuition:
        We want to find the maximum number of characters between two
        consecutive characters of `skill` when they are matched inside
        `station` in order.

        `pre[i]` stores the earliest position in `station` where skill[i]
        can be matched.

        `suf[i]` stores the latest position in `station` where skill[i]
        can be matched.

        For every pair of consecutive characters:
            skill[i-1] ... skill[i]

        The largest possible gap is:
            suf[i] - pre[i-1]

        We take the maximum of these values.

        Example:
            skill   = "abc"
            station = "axbxc"

            Earliest matching positions:
                a -> 0
                b -> 2
                c -> 4

            Latest matching positions:
                a -> 0
                b -> 2
                c -> 4

            Gaps:
                b - a = 2
                c - b = 2

            Answer = 2

        Time Complexity:
            O(n + m)

        Space Complexity:
            O(n)
    */

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size(),m=station.size();

        vector<int> pre(n),suf(n);

        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j<m && station[j]!=skill[i]) j++;
            pre[i]=j++;
        }

        j=m-1;
        for(int i=n-1;i>=0;i--)
        {
            while(j>=0 && station[j]!=skill[i]) j--;
            suf[i]=j--;
        }

        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans=max(ans,suf[i]-pre[i-1]);
        }
        return ans;
    }
};
