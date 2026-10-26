/*
Intuition:
- Convert each date from "MM-DD" format into a numerical day of the year.
- The overlapping period starts at the later of the two arrival dates.
- The overlapping period ends at the earlier of the two departure dates.
- Since both arrival and departure dates are inclusive, add 1 to the
  difference between the end and start dates.
- If the dates do not overlap, return 0.

Approach:
1. Define a helper function f() to convert a date into its day number.
2. Find the later arrival date using max().
3. Find the earlier departure date using min().
4. Calculate the overlap as end - start + 1.
5. Return max(0, overlap) to handle non-overlapping dates.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return max(0,min(f(leaveAlice),f(leaveBob))-max(f(arriveAlice),f(arriveBob))+1);
    }

    int f(auto &s)
    {
        int a=(s[0]-'0')*10 +(s[1]-'0');
        int b=(s[3]-'0')*10 +(s[4]-'0');

        return (275*a)/9-2*((a+9)/12)+b-30;
    }
};
