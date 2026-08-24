/*
    Intuition:
    Count how many times each character appears in the string.
    Then sort the characters based on their frequencies in decreasing
    order.

    Approach:
    1. Use a frequency map to count every character.
    2. Store each character and its frequency in a vector.
    3. Sort the vector in decreasing order of frequency.
    4. Append each character according to its frequency.
    5. Return the resulting string.

    Example:
    s = "tree"

    Frequencies:
    t -> 1
    r -> 1
    e -> 2

    After sorting by frequency:
    e -> 2
    t -> 1
    r -> 1

    Result:
    "eetr" or "eert"

    Time Complexity:
    O(n + k log k)

    where:
    n = length of the string
    k = number of distinct characters

    Space Complexity:
    O(n + k)
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char c:s)
        {
            freq[c]++;
        }

        vector<pair<int,char>> temp;

        for(auto &[c,cou]:freq) temp.push_back({cou,c});

        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        string ans="";
        for(auto &[cou,c]:temp)
        {
            ans+=string(cou,c);
        }
        return ans;
    }
};
