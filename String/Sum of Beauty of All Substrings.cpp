/*
    Intuition:
    For every starting index, maintain the frequency of each character
    while expanding the substring.

    The beauty of a substring is:
        maximum frequency - minimum frequency

    We calculate this for every possible substring.

    Approach:
    1. Fix the starting index `i`.
    2. Reset the frequency array.
    3. Expand the substring using `j`.
    4. Update the frequency of s[j].
    5. Find the maximum and minimum non-zero frequencies.
    6. Add their difference to the answer.

    Time Complexity:
    O(n^2 * 26) = O(n^2)

    Space Complexity:
    O(26) = O(1)
*/

class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n-1;i++)
        {
            vector<int> freq(26,0);
            freq[s[i]-'a']++;
            for(int j=i+1;j<n;j++)
            {
                freq[s[j]-'a']++;
                int mx=*max_element(freq.begin(),freq.end());
                int mi=INT_MAX;

                for(int &k:freq)
                {
                    if(k!=0)
                    {
                        mi=min(k,mi);
                    }
                }

                if(mi!=0)
                {
                    ans+=(mx-mi);
                }
            }
        }
        return ans;
    }
};
