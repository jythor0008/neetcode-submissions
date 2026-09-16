# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        # reverse new_list
        new_list = slow.next
        slow.next = None # break the link
        prev = None
        while new_list:
            nxt = new_list.next
            new_list.next = prev
            prev = new_list
            new_list = nxt
        
        # Now prev is the head of the reversed list
        cur = head
        while cur and prev:
            temp_cur = cur.next
            temp_prev = prev.next

            cur.next = prev
            prev.next = temp_cur
            cur = temp_cur
            prev = temp_prev
        


