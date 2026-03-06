/*
Problem:
Given a binary string s without leading zeros, return true if the string
contains at most one contiguous segment of '1's.

Intuition:
A valid binary string can only follow this pattern:

    0* 1* 0*

Meaning:
- Any number of zeros
- Followed by a single continuous block of ones
- Followed by zeros again

The string becomes invalid if we ever see the pattern:

    1 ... 1 0 ... 0 1

which means a second segment of ones appears.

Approach:
We track two states while traversing the string:

1. seenOne
   - Indicates that we have encountered the first segment of '1's.

2. zeroAfterOne
   - Indicates that we have encountered a '0' after the first segment
     of '1's has started.

While iterating:
- If we see '1' after zeroAfterOne becomes true, it means a second
  segment of ones has started → return false.
- Otherwise we continue scanning.

If no second segment appears, the string is valid.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroafterone=false,seenone=false;
        for(char &c : s)
        {
            if(c=='1')
            {
                if(zeroafterone)
                {
                    return false;
                }
                seenone=true;
            }
            else
            {
                if(seenone) zeroafterone=true;
            }
        }
        return true;
    }
};
