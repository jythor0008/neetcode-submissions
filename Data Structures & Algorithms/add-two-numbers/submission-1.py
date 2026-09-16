# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        carry = 0

        while l1 or l2 or carry:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            sum = a + b + carry
            val = sum%10
            carry = sum//10

            cur.next = ListNode(val)
            cur = cur.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            
        return dummy.next
