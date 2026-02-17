/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;

        // 1. Advance fast pointer n steps
        for (int i = 0; i < n; i++) {
            // If n is valid (n <= length), fast will not be null inside the loop
            fast = fast->next;
        }

        // 2. EDGE CASE: If fast is nullptr, it means n == length of list. We need to remove head.
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }

        // 3. Move both until fast reaches the LAST node (fast->next is null)
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // 4. Slow is now exactly one node BEFORE the target
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;   
    }
};
