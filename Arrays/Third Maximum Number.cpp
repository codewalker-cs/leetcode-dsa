/*
    ------------------------------------------------------------
    📝 Intuition
    ------------------------------------------------------------
    We only need to keep track of the three largest DISTINCT
    numbers seen so far.

    Maintain three variables:
        - first  -> Largest element
        - second -> Second largest distinct element
        - third  -> Third largest distinct element

    While traversing the array:
        1. Ignore duplicates.
        2. If the current number is greater than the largest,
           shift first -> second and second -> third.
        3. Otherwise update second or third accordingly.

    At the end:
        - If a third distinct maximum doesn't exist,
          return the maximum element.
        - Otherwise return the third maximum.

    We initialize the variables with LLONG_MIN instead of INT_MIN
    because the input array may itself contain INT_MIN. Using
    LLONG_MIN acts as a safe sentinel value that can never collide
    with any valid integer in the array.

    ------------------------------------------------------------
    Example Walkthrough
    ------------------------------------------------------------
    nums = [2, 2, 3, 1]

    Initially:
        first  = -∞
        second = -∞
        third  = -∞

    Read 2:
        first = 2

    Read 2:
        Duplicate -> Ignore

    Read 3:
        third  = -∞
        second = 2
        first  = 3

    Read 1:
        third = 1

    Final:
        first  = 3
        second = 2
        third  = 1

    Answer = 1

    ------------------------------------------------------------
    Time Complexity
    ------------------------------------------------------------
    O(n)

    Each element is processed exactly once.

    ------------------------------------------------------------
    Space Complexity
    ------------------------------------------------------------
    O(1)

    Only three extra variables are used.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // set<int> s;
        // for(int &i : nums)
        // {
        //     s.insert(i);
        // }

        // auto it=s.end();
        // if(s.size()<3) 
        // {
        //     --it;
        //     return *it;
        // }
        // --it;
        // --it;
        // --it;
        // return *it;

        long long first=LLONG_MIN,second=LLONG_MIN,third=LLONG_MIN;

        for(int &i : nums)
        {
            if(i==first || i==second || i==third) continue;

            if(first<i)
            {
                third=second;
                second=first;
                first=i;
            }
            else if(second<i)
            {
                third=second;
                second=i;
            }
            else if(third<i)
            {
                third=i;
            }
        }

        if(third==LLONG_MIN)
        {
            return first;
        }
        return third;
    }
};
