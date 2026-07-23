/*
    ---------------------------------------------------------
    Intuition:
    ---------------------------------------------------------
    Since the array contains only three distinct values (0, 1, and 2),
    we can sort it in a single traversal using three pointers.

    We maintain:
    - low  -> Next position for 0
    - mid  -> Current element being processed
    - high -> Next position for 2

    Rules:
    1. If nums[mid] == 0
       → Swap with nums[low]
       → Increment both low and mid

    2. If nums[mid] == 1
       → It is already in the correct region
       → Increment mid

    3. If nums[mid] == 2
       → Swap with nums[high]
       → Decrement high
       → Do NOT increment mid because the swapped element
         hasn't been processed yet.

    ---------------------------------------------------------
    Example:
    ---------------------------------------------------------
    nums = [2,0,2,1,1,0]

    low = 0
    mid = 0
    high = 5

    Step 1:
    [2,0,2,1,1,0]
     ^
    Swap nums[mid] with nums[high]

    [0,0,2,1,1,2]
     ^
    high--

    Step 2:
    nums[mid] = 0

    Swap low and mid
    low++, mid++

    [0,0,2,1,1,2]

    Step 3:
    nums[mid] = 0

    Swap low and mid
    low++, mid++

    [0,0,2,1,1,2]

    Step 4:
    nums[mid] = 2

    Swap with high

    [0,0,1,1,2,2]

    Continue until mid > high.

    Final Answer:
    [0,0,1,1,2,2]

    ---------------------------------------------------------
    Time Complexity:
    O(n)

    Each element is processed at most once.

    ---------------------------------------------------------
    Space Complexity:
    O(1)

    No extra space is used.
    ---------------------------------------------------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n=nums.size();
        
        // for(int i=0;i<n-1;i++)
        // {
        //     bool flag=false;
        //     for(int j=0;j<n-i-1;j++)
        //     {
        //         if(nums[j]>nums[j+1])
        //         {
        //             swap(nums[j+1],nums[j]);
        //             flag=true;
        //         }
        //     }

        //     if(!flag) break;
        // }

        int mid=0,low=0,high=nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
