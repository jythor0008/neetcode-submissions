# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Wrapper:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []
        for node in lists:
            if node:
                heapq.heappush(min_heap, Wrapper(node))

        cur = dummy = ListNode()
        while min_heap:
            smallest = heapq.heappop(min_heap)
            cur.next = smallest.node

            cur = cur.next
            if smallest.node.next:
                heapq.heappush(min_heap, Wrapper(smallest.node.next))

        return dummy.next