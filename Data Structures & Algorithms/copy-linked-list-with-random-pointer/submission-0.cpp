/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;

    Node* copyRandomList(Node* head) {
        Node* curr_head = head;
        while (curr_head != nullptr) {
            mp[curr_head] = new Node(*curr_head);
            curr_head = curr_head->next;
        }
        Node* curr_head_copy = mp[head];
        curr_head = head;
        while (curr_head != nullptr) {
            curr_head_copy->next = mp[curr_head->next];
            curr_head_copy->random = mp[curr_head->random];
            curr_head_copy = curr_head_copy->next;
            curr_head = curr_head->next;
        }
        return mp[head];
    }
};
