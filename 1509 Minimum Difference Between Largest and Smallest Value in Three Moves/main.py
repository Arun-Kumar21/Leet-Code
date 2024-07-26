from typing import List


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0

        smallest = sorted(nums)[:4]
        largest = sorted(nums)[-4:]

        return min(largest[-1] - smallest[3], largest[-2] - smallest[2], largest[-3] - smallest[1],
                   largest[-4] - smallest[0])

