/*
    Problem: Group Anagrams
    LeetCode: 49. Group Anagrams

    Intuition:
    - Two strings are anagrams if their sorted forms are identical.
    - Use the sorted string as a unique key.
    - Store all original strings having the same sorted key in the same group.

    Example:
    "eat" -> "aet"
    "tea" -> "aet"
    "ate" -> "aet"

    All three will be stored under the key "aet".

    Approach:
    1. Create a hashmap:
       key   = sorted version of string
       value = list of strings with that sorted form

    2. For every string:
       - Copy it.
       - Sort the copy.
       - Push the original string into the corresponding hashmap bucket.

    3. Extract all groups from the hashmap and return them.

    Time Complexity:
    - Sorting each string: O(K log K)
    - For N strings:
      O(N * K log K)

    Space Complexity:
    - O(N * K)
      (for storing grouped strings in hashmap)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());

            groups[key].push_back(str);
        }

        vector<vector<string>> result;

        for (auto &group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};
