from typing import Optional, List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        pos_critical = []

        slow = head
        fast = head.next

        current_pos = 1

        while fast.next:
            current_pos += 1

            if fast.val > fast.next.val and fast.val > slow.val or fast.val < slow.val and fast.val < fast.next.val:
                pos_critical.append(current_pos)

            fast = fast.next
            slow = slow.next

        size = len(pos_critical)

        if size == 0 or size == 1:
            return [-1, -1]

        min_dist = 999999
        max_dist = pos_critical[size-1]-pos_critical[0]

        for i in range(1, len(pos_critical)):
            min_dist = min(min_dist, pos_critical[i]-pos_critical[i-1])

        return [min_dist, max_dist]

