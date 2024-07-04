from typing import Optional


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_node: Optional[ListNode] = ListNode(0)

        res:Optional[ListNode] = dummy_node

        head = head.next
        current_sum = 0

        while head:
            if head.val == 0:
                res.next = ListNode(current_sum)
                res = res.next
                current_sum = 0

            else:
                current_sum += head.val

            head = head.next

        res.next = None

        return dummy_node.next









