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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) { 
            return false; 
            }
        unordered_map<ListNode*, int> mp;
        while (head->next != nullptr) {
            ListNode* next_node = head->next;
            if (mp.count(next_node)) { 
                return true; 
                }
            else {
                mp[head] = 1; // Visited current node.
                }
            head = head->next;
        }
        return false;
    }
};