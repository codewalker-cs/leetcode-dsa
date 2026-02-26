/*
------------------------------------------------------------
Problem: Number of Steps to Reduce a Binary Number to 1
------------------------------------------------------------

We are given a binary string representation of a number.
Rules:
1) If number is even → divide by 2
2) If number is odd  → add 1

We must return total steps required to reduce it to "1".

------------------------------------------------------------
APPROACH 1: Brute Force (Binary Simulation)
------------------------------------------------------------

Idea:
- If last bit is '0' → even → remove last bit (divide by 2)
- If last bit is '1' → odd  → perform binary +1
- Repeat until string becomes "1"

Binary +1 logic:
- Traverse from right to left
- If bit is '0', make it '1' and stop
- If bit is '1', make it '0' and continue
- If all bits were '1', insert '1' at front

Time Complexity: O(n²)
(Each add/substr operation is O(n) in worst case)

------------------------------------------------------------
APPROACH 2: Optimal (Binary Observation + Carry)
------------------------------------------------------------

Instead of modifying the string, we count operations directly.

Observation:
- If current_bit + carry == 0 → 1 step
- If current_bit + carry == 1 → 2 steps (add + divide), carry = 1
- If current_bit + carry == 2 → 1 step (divide), carry = 1

We iterate from right to left (ignore index 0).
Finally return steps + carry.

Time Complexity: O(n)
Space Complexity: O(1)

------------------------------------------------------------
*/

class Solution {
public:
    // string addone(string s)
    // {
    //     for(int i=s.size()-1;i>=0;i--)
    //     {
    //         if(s[i]=='0')
    //         {
    //             s[i]='1';
    //             return s;
    //         }
    //         else
    //         {
    //             s[i]='0';
    //         }
    //     }
    //     s.insert(0,"1");
    //     return s;
    // }

    int numSteps(string s) {
        // int count=0;
        // while(s!="1")
        // {
        //     if(s.back()=='0')
        //     {
        //         s=s.substr(0,s.size()-1);
        //         count++;
        //     }
        //     else
        //     {
        //         s=addone(s);
        //         count++;
        //     }
        // }
        // return count;

        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--) 
        {
            int bit = (s[i] - '0') + carry;

            if (bit == 0) 
            {
                steps += 1;
            } 
            else if (bit == 1) 
            {
                steps += 2;
                carry = 1;
            }
            else
            {
                steps += 1;
                carry = 1;
            }
        }

        return steps + carry;
    }
};
