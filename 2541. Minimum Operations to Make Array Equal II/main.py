from typing import List

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0: 
            return 0 if nums1 == nums2 else -1

        N = len(nums1)
        pos_sum = neg_sum = 0

        for i in range(N):
            diff = nums2[i] - nums1[i]
            if diff % k != 0:
                return -1
            
            if diff > 0:
                pos_sum += diff // k
            elif diff < 0:
                neg_sum += (-diff) // k

        if pos_sum != neg_sum:
            return -1
        
        return pos_sum  