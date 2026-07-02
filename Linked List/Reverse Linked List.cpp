/*
    LeetCode 206. Reverse Linked List

    Intuition:
    - We maintain two pointers:
        1. temp1 -> points to the current head of the reversed part.
        2. temp2 -> points to the next node that is yet to be processed.
    - In every iteration:
        - Save the current reversed head in temp3.
        - Move temp1 forward.
        - Advance temp2.
        - Connect temp1 back to temp3.
    - During the process, a temporary cycle is created because the original
      head still points to its next node.
    - After the loop, break this cycle by setting the original head's next
      pointer to NULL.
    - Finally, temp1 becomes the new head.

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp1=head;
        ListNode *temp2=head->next;
        
        while(temp2!=NULL)
        {
            ListNode *temp3=temp1;
            temp1=temp2;
            temp2=temp2->next;
            temp1->next=temp3;
        }
        head->next=NULL;
        head=temp1;
        return head;
    }
};
