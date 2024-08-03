class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        to_remove = set(nums)
        
        dummy = ListNode(0)
        dummy.next = head
        
        slow = dummy
        fast = head
        
        while fast:
            if fast.val in to_remove:
                slow.next = fast.next
            else:
                slow = fast
            
            fast = fast.next
        
        return dummy.next
