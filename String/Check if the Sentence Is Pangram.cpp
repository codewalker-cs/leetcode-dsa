/*
Intuition:
A pangram is a sentence that contains every letter of the English alphabet
at least once (i.e., all 26 lowercase letters from 'a' to 'z').

Approach:
1. First check the length of the string.
   - If the length is less than 26, it cannot possibly contain all 26 letters,
     so we directly return false.

2. Create a frequency array of size 26 to track the occurrence of each letter.

3. Traverse the string:
   - For each character 'c', compute its index using (c - 'a').
   - Increment the corresponding position in the frequency array.

4. After filling the frequency array, check if any letter frequency is 0.
   - If any index has 0, it means that character did not appear → not a pangram.

5. If all letters appear at least once, return true.

Time Complexity: O(n)
- We traverse the string once.

Space Complexity: O(1)
- The frequency array has fixed size 26.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int s=sentence.size();
        if(s<26) return 0;
       
        vector<int> freq(26,0);
    
        for(char &c : sentence)
        {
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0) return 0;
        }
        return 1;
    }
};
