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
        if (head->next == nullptr) { return; }
        queue<ListNode*> left;
        stack<ListNode*> right;
        ListNode* curr_node = head;
        int size = 0;
        while (curr_node != nullptr) {
            size += 1;
            right.push(curr_node);
            left.push(curr_node);
            curr_node = curr_node->next;
        }
        ListNode* newHead = left.front();
        left.pop();
        for (int i = 2; i <= size; i++) {
            if (i % 2 == 0) {
                newHead->next = right.top();
                right.pop();
            } else {
                newHead->next = left.front();
                left.pop();
            }
            newHead = newHead->next;
            if (i == size) {
                newHead->next = nullptr;
            }
        }
    }
};
