# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # split this into iterations group by group
        # we need PrevGroupEnd, nextGroupStart
        # CurGroupStart will become CurGroupEnd
        # CurGroupEnd will become CurGroupStart

        dummy = ListNode(0, head)
        prev_end = dummy
        cur_start = dummy.next
        while cur_start:
            cur_end = prev_end
            for i in range(k):
                cur_end = cur_end.next
                if not cur_end:
                    return dummy.next

            # Reverse the nodes in this group from cur_start until cur_end
            next_start = cur_end.next
            cur_end.next = None

            prev = None
            cur = cur_start
            while cur:
                temp = cur.next
                cur.next = prev
                prev = cur
                cur = temp
            
            prev_end.next = cur_end
            cur_start.next = next_start
            prev_end = cur_start
            cur_start = next_start
        
        return dummy.next

            