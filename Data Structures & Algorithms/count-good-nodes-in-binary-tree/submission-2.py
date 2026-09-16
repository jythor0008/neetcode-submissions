# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # DFS, keep track of largest number seen thus far and continue on the road
        stack = []
        if not root:
            return 0

        res = 0
        stack.append((root, root.val))
        while stack:
            cur, value = stack.pop()

            if cur.val >= value:
                res += 1

            if cur.left:
                stack.append((cur.left, max(cur.val, value)))
            if cur.right:
                stack.append((cur.right, max(cur.val, value)))
        
        return res

