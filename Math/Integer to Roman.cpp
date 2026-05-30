// Intuition:
// Roman numerals can be constructed greedily.
//
// We keep all possible Roman values in descending order:
//
// 1000 -> M
// 900  -> CM
// 500  -> D
// 400  -> CD
// ...
// 1    -> I
//
// For each value, while the current number is at least that value,
// append its Roman symbol and subtract the value.
//
// Since the Roman numeral system is designed using these standard
// symbols and subtractive forms, the greedy choice always produces
// the correct answer.
//
// Time Complexity: O(1)
// (At most a few dozen operations since num <= 3999)
//
// Space Complexity: O(1)

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman ={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        string ans;
        for(auto &[value,symbol] : roman)
        {
            while(num>=value)
            {
                ans+=symbol;
                num-=value;
            }
        }
        return ans;
    }
};
