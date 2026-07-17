/*
========================================
        Reorder List (LeetCode 143)
========================================

Intuition:
-----------
The reordered list follows the pattern:

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 ...

Instead of repeatedly taking the last node (which would cost O(n²)),
we can solve the problem in three linear passes.

Step 1:
Find the middle of the linked list using the slow and fast pointer technique.

Example:
1 → 2 → 3 → 4 → 5

slow stops at 3.

First Half:
1 → 2 → 3

Second Half:
4 → 5

--------------------------------------------------

Step 2:
Reverse the second half of the list.

Before:
4 → 5

After:
5 → 4

Now we have:

First:
1 → 2 → 3

Second:
5 → 4

--------------------------------------------------

Step 3:
Merge the two halves alternately.

Take one node from the first list,
then one node from the reversed second list.

Process:

1 → 2 → 3
5 → 4

Iteration 1:
1 → 5 → 2 → 3

Iteration 2:
1 → 5 → 2 → 4 → 3

Final Answer:
1 → 5 → 2 → 4 → 3

--------------------------------------------------

Algorithm:
----------
1. Find the middle using slow and fast pointers.
2. Split the list into two halves.
3. Reverse the second half.
4. Merge both halves alternately.

Time Complexity:
----------------
O(n)

- Finding middle  : O(n)
- Reversing list  : O(n)
- Merging halves  : O(n)

Overall: O(n)

Space Complexity:
-----------------
O(1)

Only a few pointers are used.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while (second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
