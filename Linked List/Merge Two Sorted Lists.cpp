/*
    LeetCode 21. Merge Two Sorted Lists

    ------------------------------------------------------------
    Intuition 1: Iterative Approach (Dummy Node) [Recommended]
    ------------------------------------------------------------

    We are given two sorted linked lists.
    Since both lists are already sorted, at every step we only need
    to choose the smaller node and attach it to our answer.

    Instead of worrying about the first node separately, we create
    a dummy node.

    dummy -> NULL

    A pointer 'tail' always points to the last node of the merged list.

    Algorithm:
    1. Create a dummy node.
    2. Compare the current nodes of both lists.
    3. Attach the smaller node to tail.
    4. Move tail forward.
    5. Move the pointer of the list from which the node was taken.
    6. Repeat until one list becomes empty.
    7. Attach the remaining list.
    8. Return dummy.next.

    Example:

    list1 : 1 -> 2 -> 4
    list2 : 1 -> 3 -> 4

    dummy

    dummy -> 1
               ^
             tail

    dummy -> 1 -> 1
                    ^
                  tail

    dummy -> 1 -> 1 -> 2
                         ^
                       tail

    dummy -> 1 -> 1 -> 2 -> 3
                              ^
                            tail

    dummy -> 1 -> 1 -> 2 -> 3 -> 4
                                   ^
                                 tail

    Attach remaining list:
    dummy -> 1 -> 1 -> 2 -> 3 -> 4 -> 4

    Time Complexity : O(n + m)
    Space Complexity: O(1)



    ------------------------------------------------------------
    Intuition 2: Recursive Approach
    ------------------------------------------------------------

    Think recursively.

    If one list is empty, simply return the other list.

    Otherwise:

    • If list1->val <= list2->val
      then list1 should come first.

      Connect list1 to the merged result of

          list1->next and list2

    • Else

      list2 should come first.

      Connect list2 to the merged result of

          list1 and list2->next

    Eventually one list becomes empty and recursion starts
    returning the merged list.

    Time Complexity : O(n + m)
    Space Complexity: O(n + m)
    (Recursion stack)
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


// ============================================================================
// Iterative Solution (Preferred)
// ============================================================================

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node before the actual merged list
        ListNode dummy;

        // Tail always points to the last node of merged list
        ListNode* tail = &dummy;

        // Merge while both lists have nodes
        while (list1 && list2) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach whichever list is left
        tail->next = (list1) ? list1 : list2;

        return dummy.next;
    }
};


// ============================================================================
// Recursive Solution
// ============================================================================

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *head=NULL;
        ListNode *nxt;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                if(head==NULL)
                {
                    head=list1;
                    nxt=head;
                }
                else
                {
                    nxt->next=list1;
                    nxt=nxt->next;
                }
                list1=list1->next;
            }
            else
            {
                if(head==NULL)
                {
                    head=list2;
                    nxt=head;
                }
                else
                {
                    nxt->next=list2;
                    nxt=nxt->next;
                }
                list2=list2->next;
            }
        }

        if(list1!=NULL)
        {
            nxt->next=list1;
        }
        else
        {
            nxt->next=list2;
        }
        return head;
    }
};
