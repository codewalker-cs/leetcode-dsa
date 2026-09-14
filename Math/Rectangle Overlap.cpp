/*
    Intuition:
    ------------
    A rectangle overlaps another rectangle only if their projections
    overlap on BOTH axes:

        1. X-axis:
           r1's left edge  < r2's right edge
           r1's right edge > r2's left edge

        2. Y-axis:
           r1's bottom edge < r2's top edge
           r1's top edge    > r2's bottom edge

    We use strict inequalities because touching at an edge or corner
    does NOT count as an overlap.

    For a rectangle:

        [x1, y1, x2, y2]

        x1 = left
        y1 = bottom
        x2 = right
        y2 = top

    Therefore, all four conditions must be true.

    Approach:
    ----------
    Check that:
        - The rectangles overlap horizontally.
        - The rectangles overlap vertically.

    If both are true, the rectangles have a positive-area
    intersection.

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        return r1[0] < r2[2] &&
               r1[2] > r2[0] &&
               r1[1] < r2[3] &&
               r1[3] > r2[1];
    }
};
