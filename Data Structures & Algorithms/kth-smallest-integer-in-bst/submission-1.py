# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        cur = root
        while stack or cur:
            # Add in all the left children
            while cur:
                stack.append(cur)
                cur = cur.left

            # now we reach the most left
            cur = stack.pop()
            k -= 1
            if k == 0:
                return cur.val
            
            if cur.right:
                cur = cur.right
            else:
                cur = None
        return -1


