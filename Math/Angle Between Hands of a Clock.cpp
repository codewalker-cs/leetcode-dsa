/*
    LeetCode 1344 - Angle Between Hands of a Clock

    Intuition:
    - The minute hand moves 360° in 60 minutes.
      => 1 minute = 6°.
    - The hour hand moves 360° in 12 hours.
      => 1 hour = 30°.
    - The hour hand also moves continuously as minutes pass.
      => 1 minute = 0.5° for the hour hand.

    Steps:
    1. Compute the angle of the minute hand.
    2. Compute the angle of the hour hand.
    3. Find the absolute difference between them.
    4. Return the smaller angle between:
       - diff
       - 360 - diff

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

// class Solution {
// public:
//     double angleClock(int hour, int minutes) {
//         double min=(minutes*180)/30;
//         double hr=(((hour*5)+((minutes*2.5/30)))*180)/30;

//         return min(abs(min-hr),360-abs(min-hr));
//         }
// };

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minu=minutes*6;
        double hr=hour*30+minutes*0.5;

        double diff=abs(minu-hr);

        return min(diff,360-diff);
        }
};
