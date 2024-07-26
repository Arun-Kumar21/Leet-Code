from typing import List;

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counter = {}

        for n in nums:
            counter[n] = 1 + counter.get(n, 0)

        def custom_sort(n):
            return (counter[n], -n)

        nums.sort(key=custom_sort)

        return nums



