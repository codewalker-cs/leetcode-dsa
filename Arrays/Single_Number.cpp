/*
Pattern: Bit Manipulation (XOR)

Key Observations:
- a ^ a = 0
- a ^ 0 = a
- XOR is commutative

Why it matters:
- Used in low-memory systems
- Appears in cybersecurity & low-level optimization

Explain:
- Here we use XOR on each value in vector as given there is only one unique number rest are present in pairs so we eleminate them using XOR
and than only remaining one is the unique one.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s=0;
        for(int i:nums)
        {
            s^=i;
        }
        return s;
    }
};
