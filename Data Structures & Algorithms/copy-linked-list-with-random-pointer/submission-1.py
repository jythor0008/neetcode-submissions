"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # use map to map each head to its copy first
        # Once all done then we loop through again to update the next and random pointers
        map_ = {}
        map_[None] = None
        cur = head
        while cur:
            map_[cur] = Node(cur.val)
            cur = cur.next
        
        cur = head
        while cur:
            copy = map_[cur]
            copy.next = map_[cur.next]
            copy.random = map_[cur.random]
            cur = cur.next

        return map_[head]