# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = None
        try:
            result = ListNode(head.val, None)
        except:
            return head
        node = head
        while node.next is not None:
            node = node.next
            result = ListNode(node.val, result)
        return result