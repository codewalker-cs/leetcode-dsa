/*
    Intuition:
    ------------
    We need to find the minimum number of swaps required to sort the
    array according to the following rules:

        1. Sort by the sum of digits in increasing order.
        2. If two numbers have the same digit sum, sort them by
           their numerical value in increasing order.

    First, we calculate the digit sum of every number and store it
    in a hash map.

    We then create a sorted copy of the original array using the
    required comparator.

    To minimize swaps, we use a position map that stores the current
    index of each element.

    For every index i:
        - If nums[i] already equals the target value, continue.
        - Otherwise, find the current position j of the target value.
        - Swap nums[i] with nums[j].
        - Update the position map.
        - Increment the swap count.

    Since every swap places the correct element at the current index,
    we obtain the minimum number of swaps.

    Approach:
    ----------
    1. Calculate and store the digit sum of each number.
    2. Sort a copy of the array using digit sum and numerical value.
    3. Store the current positions of the elements.
    4. Traverse the array and swap misplaced elements into their
       correct positions.
    5. Update the position map after every swap.
    6. Return the total number of swaps.

    Time Complexity:
    O(n log n)

    Sorting takes O(n log n), and the position-based swapping takes
    O(n) expected time using an unordered_map.

    Space Complexity:
    O(n)

    The sorted copy, digit-sum map, and position map require O(n)
    additional space.
*/

class Solution {
public:
    int findsum(int n)
    {
        int ans=0,temp=n;
        while(temp!=0)
        {
            ans+=temp%10;
            temp/=10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>s=nums;
        unordered_map<int,int> freq,pos;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]=findsum(nums[i]);
        }

        sort(s.begin(),s.end(),[&](int a,int b){
            if(freq[a]==freq[b]){
                return a<b;
            }
            return freq[a]<freq[b];
        });

        for(int i=0;i<n;i++)
        {
            pos[nums[i]]=i;
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==s[i])
            {
                continue;
            }

            int j=pos[s[i]];
            pos[nums[i]]=j;
            pos[s[i]]=i;
            swap(nums[i],nums[j]);
            ans++;
        }
        return ans;
    }
};
