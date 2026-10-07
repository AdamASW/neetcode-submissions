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
        // Define head of new and a pointer to the prev node.
        ListNode* newNode;
        ListNode* prevNode;
        
        // Define a carry bool to check if we 'carry over the 1'.
        bool carry = false;
        int sum = 0;
        int dig = 1;
        int l1Val, l2Val;

        // Iterate across l1 and l2, 
        while (l1 != nullptr || l2 != nullptr) {
            // Get digit and set to 0 if DNE for current digit.
            l1Val = (l1 != nullptr) ? l1-> val : 0;
            l2Val = (l2 != nullptr) ? l2-> val : 0;
            sum = (l1Val + l2Val);
            // If carry is true from the previous run, we add 1 automatically.
            if (carry) { sum += 1; }
            // If digit value, including the additional carry if applicable, is now >= 10,
            // we mark carry true again to ensure next digit is carried over.
            carry = (sum >= 10) ? true : false;
            // If the current digit value results in a carry, we decrement by 10 to give
            // current node a proper value.
            sum = (carry) ? (sum - 10) : sum;

            // Now we properly define the current node
            ListNode* currNode = new ListNode(sum);
            if (dig == 1) {
                newNode = currNode;
            } else {
                prevNode->next = currNode;
            }
            prevNode = currNode;
            // currNode->next update will be done by prevNode->next update in following iteration.
            // Lastly, iterate on l1 and l2 unless they're nullptrs.
            l1 = (l1 != nullptr) ? l1->next : l1;
            l2 = (l2 != nullptr) ? l2->next : l2;
            dig++;
        }

        // If carry == true and the loop has ended, an extra '1' digit is required.
        if (carry) {
            ListNode* currNode = new ListNode(1);
            prevNode->next = currNode;
        }

        // Return the head of the new list.
        return newNode;
    }
};
