/**
 * Problem : Add Two Numbers
 * LeetCode : 2
 *
 * ---------------------------------------------------------
 * Intuition
 * ---------------------------------------------------------
 * The linked lists already store digits separately.
 * Instead of converting them into integers (which can overflow),
 * we add one digit at a time exactly like manual addition.
 *
 * Example:
 *
 *      342
 *    + 465
 *    -----
 *      807
 *
 * Digits are stored in reverse:
 *
 * l1 : 2 -> 4 -> 3
 * l2 : 5 -> 6 -> 4
 *
 * Process:
 *
 * 2 + 5 = 7
 * 4 + 6 = 10 -> write 0, carry 1
 * 3 + 4 + 1 = 8
 *
 * Answer:
 * 7 -> 0 -> 8
 *
 * ---------------------------------------------------------
 * Algorithm
 * ---------------------------------------------------------
 * 1. Maintain a carry.
 * 2. Traverse both linked lists simultaneously.
 * 3. Add:
 *      digit1 + digit2 + carry
 * 4. Create a new node containing (sum % 10).
 * 5. Update carry = sum / 10.
 * 6. Continue until both lists and carry are exhausted.
 *
 * ---------------------------------------------------------
 * Time Complexity : O(max(n,m))
 * Space Complexity: O(max(n,m))   (output list only)
 * ---------------------------------------------------------
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0);
        ListNode *tail=l3;

        int carry=0;

        while(l1 || l2 || carry)
        {
            int sum=carry;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }

            carry=sum/10;

            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }

        return l3->next;
    }
};
