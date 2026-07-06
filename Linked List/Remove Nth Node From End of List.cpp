/*
=========================================================
        Remove Nth Node From End of List (LeetCode 19)
=========================================================

There are two popular approaches:

1. Two Pass (Length of Linked List)
   • First find the length.
   • Then find the node just before the one to delete.
   • Remove the target node.

   Time Complexity  : O(N)
   Space Complexity : O(1)

---------------------------------------------------------

2. One Pass (Fast & Slow Pointer) ⭐ Interview Preferred
   • Move fast pointer n+1 steps ahead.
   • Move both pointers together.
   • When fast reaches NULL,
     slow will be just before the node to delete.

   Time Complexity  : O(N)
   Space Complexity : O(1)

=========================================================
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

    //=========================================================
    // Approach 1 : Two Pass (Find Length)
    //=========================================================

    /*
        Intuition
        ---------
        If we know the total length of the list,
        then removing the Nth node from the end becomes easy.

        Position from front =
        Length - N

        Example:

        1 -> 2 -> 3 -> 4 -> 5

        Length = 5
        N = 2

        Node to delete = 4

        Position from front = 5 - 2 = 3

        So we move to node 3,
        then simply skip node 4.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *tem=head;
        while(tem)
        {
            len++;
            tem=tem->next;
        }
        if(n==len)
        {
            head=head->next;
            return head;
        }

        int nod=len-n;
        ListNode *temp=head;
        ListNode *temp2=head->next;
        while(nod!=1)
        {
            if(temp) temp=temp->next;
            if(temp2) temp2=temp->next;
            nod--;
        }
        temp->next=temp2->next;
        return head;
    }
};

    //=========================================================
    // Approach 2 : One Pass (Fast & Slow Pointer)
    //=========================================================

    /*
        Intuition
        ---------

        Create a dummy node.

                    dummy
                      |
                      v
        0 -> 1 -> 2 -> 3 -> 4 -> 5

        Move fast pointer (n+1) steps ahead.

        Why n+1 ?

        Because we want slow pointer to stop
        one node BEFORE the node to delete.

        Example:

        1 -> 2 -> 3 -> 4 -> 5
        n = 2

        Initial

        S
        F
        |
        D -> 1 -> 2 -> 3 -> 4 -> 5

        Move fast 3 steps

        D -> 1 -> 2 -> 3 -> 4 -> 5
        S              F

        Move both together

        Step 1

        D -> 1 -> 2 -> 3 -> 4 -> 5
             S              F

        Step 2

        D -> 1 -> 2 -> 3 -> 4 -> 5
                  S              F

        Step 3

        D -> 1 -> 2 -> 3 -> 4 -> 5
                       S              F(NULL)

        Slow is now just before node 4.

        Skip node 4.

        1 -> 2 -> 3 -> 5
    */

    ListNode* removeNthFromEnd_FastSlow(ListNode* head, int n) {

        // Dummy node handles deletion of head easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer (n+1) steps
        for (int i = 0; i <= n; i++)
            fast = fast->next;

        // Maintain the gap
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove target node
        slow->next = slow->next->next;

        return dummy->next;
    }

    //=========================================================
    // LeetCode Function
    //=========================================================

    /*
        Interview Preferred:
        --------------------
        Use Fast & Slow Pointer because it
        solves the problem in one traversal.
    */

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Uncomment whichever approach you want.

        // return removeNthFromEnd_Length(head, n);

        return removeNthFromEnd_FastSlow(head, n);
    }
};
