"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node
            
        hm = {}

        def dfs(cur):
            hm[cur] = Node(cur.val) # Create the node

            # Link up the neighbors
            for neigh in cur.neighbors:
                if neigh not in hm:
                    # Use dfs to create and link neighbors
                    dfs(neigh)

                # Link this neighbor
                hm[cur].neighbors.append(hm[neigh])

        cur = node
        dfs(cur)

        return hm[node]
                
