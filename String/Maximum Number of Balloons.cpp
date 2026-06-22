/*
Problem: Maximum Number of Balloons

Intuition:
To form the word "balloon", we need:
b -> 1
a -> 1
l -> 2
o -> 2
n -> 1

Count the frequency of every character in the string.
The number of balloons we can form is limited by the character
that runs out first. Since 'l' and 'o' are needed twice, divide
their frequencies by 2 before taking the minimum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // int n=text.size();
        // string s="ballon";
        // unordered_map<char,int> freq;

        // for(char &c : s)
        // {
        //     freq[c]=0;
        // }

        // for(char &t:text)
        // {
        //     if(freq.find(t)!=freq.end()) freq[t]++;
        // }

        // int m=freq['b'];
        // for(auto &a : freq)
        // {
        //     if(a.first!='l' && a.first!='o' && a.second!=m)
        //     {
        //         m=min(m,a.second);
        //     }
        //     else if((a.first=='l' || a.first=='o') && a.second!=(m*2))
        //     {
        //         m=min(m,(a.second/2));
        //     }
        // }
        // return m;

        unordered_map<char,int> freq;

        for(char &c : text)
        {
            freq[c]++;
        }

        return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
    }
};
