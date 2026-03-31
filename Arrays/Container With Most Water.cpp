/*
 * Container With Most Water
 *
 * Intuition:
 * ----------
 * We are given an array where each element represents the height of a vertical line.
 * We need to choose two lines such that they form a container holding the maximum water.
 *
 * Brute Force:
 * ----------
 * Check all pairs → O(n^2), which is too slow.
 *
 * Optimal Approach (Two Pointers):
 * ----------
 * - Start with two pointers:
 *     l = 0 (left), r = n-1 (right)
 * - The width is (r - l)
 * - The height is min(height[l], height[r])
 * - Area = width * height
 *
 * Key Greedy Insight:
 * ----------
 * The area is limited by the shorter line.
 * So:
 * - If height[l] < height[r], move l++
 * - Else move r--
 *
 * Why?
 * Moving the taller line won't increase area because the shorter one still limits it.
 * Only moving the shorter line might lead to a better height.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,n=height.size(),r=n-1;
        
        long long area=(r-l)*(min(height[l],height[r]));

        while(l<r)
        {
            area=max(area,(long long)(r-l)*(min(height[l],height[r])));
            
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return (int)area;
    }
};
