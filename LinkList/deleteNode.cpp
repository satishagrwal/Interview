/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy data from next node to current node
        node->val = node->next->val;
        
        // Save the next node to delete it
        ListNode *temp = node->next;
        
        // Skip the next node
        node->next = node->next->next;
        delete temp;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // 1. Create a linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // 2. Identify the node to be deleted (node with value 5)
    ListNode* target = head->next;

    std::cout << "Original List: ";
    printList(head);

    // 3. Run the deletion logic
    Solution sol;
    sol.deleteNode(target);

    std::cout << "Updated List:  ";
    printList(head);

    return 0;
}
