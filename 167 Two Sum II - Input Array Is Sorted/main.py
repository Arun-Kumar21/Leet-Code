from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, h = 0, len(numbers)-1

        while l <= h:
            cur_sum = numbers[l]+numbers[h]

            if cur_sum == target:
                return [l+1, h+1]
            elif cur_sum < target:
                l += 1
            else:
                h -= 1

        return [l+1, h+1]
