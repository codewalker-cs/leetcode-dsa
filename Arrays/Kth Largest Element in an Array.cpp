// Intuition:
// We use a min-heap (priority queue) of size k.
// The heap stores the k largest elements seen so far.
// If size exceeds k, we remove the smallest element.
// At the end, the top of the heap is the kth largest element.
//
// Time Complexity: O(n log k)
// Space Complexity: O(k)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

//--------------------------------------------------------------------------------

// Intuition(2):
// We use Quickselect but improve it using RANDOMIZED PIVOT.
// This prevents worst-case O(n^2) behavior on sorted inputs.
//
// Key idea:
// Random pivot → balanced partitions → average O(n)

class Solution {
public:
    int partition(vector<int>& nums, int low, int high)
    {
        // Random pivot selection
        int pivotIndex = low + rand() % (high - low + 1);
        swap(nums[pivotIndex], nums[high]);

        int pivot = nums[high];
        int i = low;

        for(int j = low; j < high; j++)
        {
            if(nums[j] <= pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);
        return i;
    }

    int quickSelect(vector<int>& nums, int low, int high, int target)
    {
        while(low <= high)
        {
            int pi = partition(nums, low, high);

            if(pi == target) return nums[pi];
            else if(pi < target)
                low = pi + 1;
            else
                high = pi - 1;
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int target = n - k;

        return quickSelect(nums, 0, n - 1, target);
    }
};
