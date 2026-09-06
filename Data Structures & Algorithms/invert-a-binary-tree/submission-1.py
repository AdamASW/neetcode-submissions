# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root
        elif root.left is not None and root.right is not None:
            return TreeNode(root.val, self.invertTree(root.right), self.invertTree(root.left))
        elif root.left is not None:
            return TreeNode(root.val, None, self.invertTree(root.left))
        elif root.right is not None:
            return TreeNode(root.val, self.invertTree(root.right), None)
        else:
            return TreeNode(root.val)
        