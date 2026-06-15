/*
Intuition:
We first count the total number of nodes in the linked list.

If the list contains n nodes, the middle node is located at index n / 2
(0-based indexing).

After finding the size:
1. Traverse again until reaching the node just before the middle node.
2. Skip the middle node by changing pointers.
3. Return the modified list.

Example:
1 -> 2 -> 3 -> 4 -> 5

Size = 5
Middle index = 5 / 2 = 2 (node with value 3)

Move to node 2:
1 -> 2 -> 3 -> 4 -> 5
     ^

Skip node 3:
1 -> 2 ------> 4 -> 5

Time Complexity: O(n)
Space Complexity: O(1)
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            // delete head;
            return NULL;
        }

        ListNode *temp=head;
        int s=0;

        while(temp!=NULL)
        {
            s++;
            temp=temp->next;
        }

        temp=head;
        int h=s/2;

        for(int i=0;i<h-1;i++)
        {
            temp=temp->next;
        }

        ListNode *del=temp->next;
        temp->next=del->next;
        // delete del;

        return head;
    }
};

/*
Intuition:
Instead of counting all nodes first, we can find the middle node
in a single traversal.

We use:
- slow pointer -> moves 1 step at a time
- fast pointer -> moves 2 steps at a time

When fast reaches the end:
slow will be standing at the middle node.

We also maintain a prev pointer which always stays one node
behind slow.

Example:
1 -> 2 -> 3 -> 4 -> 5

Initially:
prev = NULL
slow = 1
fast = 1

Iteration 1:
prev = 1
slow = 2
fast = 3

Iteration 2:
prev = 2
slow = 3
fast = 5

Fast cannot move further.
Slow is at the middle node (3).

Delete middle:
prev->next = slow->next

Result:
1 -> 2 -> 4 -> 5

Time Complexity: O(n)
Space Complexity: O(1)

This is the preferred interview solution because it finds
the middle in a single traversal.
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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;

        return head;
    }
};
