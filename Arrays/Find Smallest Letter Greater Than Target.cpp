/*
    Problem:
    Given a sorted array of characters `letters` and a character `target`,
    find the smallest character in the array that is strictly greater than `target`.
    The array is circular, meaning if no such character exists, return letters[0].

    Initial (Naive) Intuition:
    - Traverse the array linearly.
    - Return the first character whose ASCII value is greater than `target`.
    - If none is found, return the first character.
    - This works but takes O(n) time.

    Optimized Intuition:
    - The array is already sorted → binary search can be applied.
    - We want the "first character greater than target" (upper bound).
    - Use binary search to narrow down the smallest valid character.
    - Keep storing a possible answer and try to find a smaller one on the left.
    - If target is greater than or equal to the last character,
      wrap around and return letters[0].

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // for(char& x:letters)
        // {
        //     if((int(x)-int(target))>0)
        //     {
        //         return x;
        //     }
        // }
        // return letters[0];

        int mid,start=0,end=letters.size()-1;
        char min=letters[0];
        if(int(letters[letters.size()-1])<=int(target))
        {
            return letters[0];
        }
        while(start<=end)
        {
            mid=start+((end-start)/2);
            if(int(letters[mid])>int(target))
            {
                end=mid-1;
                min=letters[mid];
            }
            else
            {
                start=mid+1;
            }
        }
        return min;
    }
};
