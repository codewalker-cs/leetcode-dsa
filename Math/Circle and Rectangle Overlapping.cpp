/*
    Intuition:
    ------------
    To check whether a circle overlaps with a rectangle, we find
    the point inside the rectangle that is closest to the center
    of the circle.

    For the x-coordinate:
        clamp(xCenter, x1, x2)

    gives:
        - x1, if the circle center is left of the rectangle
        - x2, if the circle center is right of the rectangle
        - xCenter, if the center is inside the rectangle

    We do the same for the y-coordinate.

    The distance between the circle center and this closest point
    is then calculated using the squared distance formula:

        distance² = dx² + dy²

    If this distance is less than or equal to the squared radius,
    the circle overlaps the rectangle.

    Approach:
    ----------
    1. Find the closest x-coordinate on the rectangle to the circle
       center using `clamp()`.
    2. Find the closest y-coordinate similarly.
    3. Calculate the squared distance between this point and the
       circle center.
    4. Check whether:
           distance² <= radius²

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int p1=clamp(xCenter,x1,x2)-xCenter;
        int p2=clamp(yCenter,y1,y2)-yCenter;

        return (p1*p1 + p2*p2)<=radius*radius;
    }
};
