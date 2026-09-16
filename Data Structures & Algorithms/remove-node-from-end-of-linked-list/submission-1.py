# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fast = head
        for i in range(n):
            fast = fast.next
        
        cur = dummy
        while fast:
            fast = fast.next
            cur = cur.next

        cur.next = cur.next.next
        return dummy.next
            

