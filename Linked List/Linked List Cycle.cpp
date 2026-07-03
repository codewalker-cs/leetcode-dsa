/*
    LeetCode 141. Linked List Cycle

    ------------------------------------------------------------
    Intuition 1: Store Visited Nodes (Vector)
    ------------------------------------------------------------

    Idea:
    Traverse the linked list while storing the address of every
    visited node.

    If we ever encounter a node whose address has already been
    stored, it means we have visited the same node twice,
    therefore a cycle exists.

    Example:

        3 → 2 → 0 → -4
            ↑       ↓
            └───────┘

    Visited addresses:

        [3]
        [3,2]
        [3,2,0]
        [3,2,0,-4]

    Next node = 2

    Address of node 2 is already present
    ⇒ Cycle detected.

    Drawback:
    Using vector requires a linear search (find()) every time.

    Time Complexity:
        O(n²)

    Space Complexity:
        O(n)



    ------------------------------------------------------------
    Intuition 2: Store Visited Nodes (Hash Set)
    ------------------------------------------------------------

    Instead of a vector, use an unordered_set.

    Checking whether a node has already been visited becomes
    O(1) on average.

    Algorithm:
    1. Traverse the list.
    2. If current node exists in the set,
       return true.
    3. Otherwise insert it into the set.
    4. Continue until NULL.

    Time Complexity:
        O(n)

    Space Complexity:
        O(n)



    ------------------------------------------------------------
    Intuition 3: Floyd's Cycle Detection (Tortoise & Hare)
    ------------------------------------------------------------

    This is the optimal solution.

    Use two pointers:

    slow -> moves one step

    fast -> moves two steps

    If there is NO cycle:

        slow eventually reaches NULL
        or
        fast reaches NULL

    If there IS a cycle:

        Since fast moves faster than slow,
        it will eventually catch up to slow.

    Example:

            1 → 2 → 3 → 4
                ↑       ↓
                └───────┘

    Initially

        S,F
         |
         1 → 2 → 3 → 4
             ↑       ↓
             └───────┘

    Move

    Step 1

        S
          |
        1 → 2 → 3 → 4
             ↑       ↓
             └───────┘
              |
              F

    Step 2

            S
            |
        1 → 2 → 3 → 4
             ↑       ↓
             └───────┘
                |
                F

    Step 3

                S,F
                 |
        1 → 2 → 3 → 4
             ↑       ↓
             └───────┘

    Slow and Fast meet.

    Therefore,
    cycle exists.

    Why does this work?

    Inside the cycle,
    fast gains one node on slow every iteration.

    Eventually,
    the distance between them becomes zero,
    so they must meet.

    Time Complexity:
        O(n)

    Space Complexity:
        O(1)

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// ================================================================
// Solution 1 : Vector (Brute Force)
// Time : O(n²)
// Space: O(n)
// ================================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {

        vector<ListNode*> visited;

        while (head) {

            if (find(visited.begin(), visited.end(), head) != visited.end())
                return true;

            visited.push_back(head);

            head = head->next;
        }

        return false;
    }
};



// ================================================================
// Solution 2 : Hash Set (Better)
// Time : O(n)
// Space: O(n)
// ================================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> visited;

        while (head) {

            if (visited.count(head))
                return true;

            visited.insert(head);

            head = head->next;
        }

        return false;
    }
};



// ================================================================
// Solution 3 : Floyd's Cycle Detection (Optimal)
// Time : O(n)
// Space: O(1)
// ================================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};
