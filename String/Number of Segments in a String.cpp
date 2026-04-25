// Intuition:
// We need to count the number of "segments" (words) in the string.
// A segment is defined as a contiguous sequence of non-space characters.
//
// Key idea:
// A new word always starts when:
// 1. Current character is NOT a space
// 2. AND either:
//    - It is the first character of the string (i == 0), OR
//    - The previous character is a space
//
// This way, we only count the *starting point* of each word,
// avoiding overcounting characters inside the same word.
//
// Example:
// "  hello   world  "
//            ^      ^
//        start of words → count = 2
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countSegments(string s) {
        int count=0,n=s.size();
        
        for(int i = 0; i < n; i++)
        {
            if(s[i]!=' ' && (i==0 || s[i-1]==' '))
            {
                count++;
            }
        }
        return count;
    }
};
