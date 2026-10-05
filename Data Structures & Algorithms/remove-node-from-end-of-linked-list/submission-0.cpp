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
        ListNode* curr_head = head;
        int size = 0;
        while (curr_head != nullptr) {
            size++;
            curr_head = curr_head->next;
        }
        int remove_idx = size-n+1; // 1-indexed.
        if (remove_idx == 1) {
            return head->next; // Remove first element.
        }
        curr_head = head;
        for (int i = 1; i < remove_idx; i++) {
            if (i == remove_idx - 1) {
                // ?: operation handles the case where we remove the last index.
                // Current logic can never result in nullptr->next.
                curr_head->next = (curr_head->next->next != nullptr) ? curr_head->next->next : nullptr;
                return head;
            }
            curr_head = curr_head->next;
        }
    }
};
