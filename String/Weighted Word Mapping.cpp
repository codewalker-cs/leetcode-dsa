/*
Intuition:
For each word, compute the total weight of all its characters.

- weights[i] stores the weight of the character ('a' + i).
- For every character in a word, add its corresponding weight to get
  the word's total weight.
- Take totalWeight % 26 to obtain a value in the range [0, 25].
- Map this value to a character in reverse alphabetical order:
      0  -> 'z'
      1  -> 'y'
      ...
      25 -> 'a'
  using:
      'z' - (totalWeight % 26)

Append the resulting character for each word to the answer string.

Time Complexity: O(T)
where T is the total number of characters across all words.

Space Complexity: O(1)
excluding the output string.
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string s="";

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(char &c : words[i])
            {
                sum+=weights[c-'a'];
            }
            s+=char('z'-(sum%26));
        }

        return s;
    }
};
