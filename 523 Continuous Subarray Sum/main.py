from typing import List

class Solution:
    # Optimise approach
    def check_subarray_sum(self, nums: List[int], k: int) -> bool:
        """
            Time complexity -> O(N)
        """
        mod_map = {0: -1}
        running_sum = 0

        for i in range(len(nums)):
            running_sum += nums[i]
            mod = running_sum % k

            if mod in mod_map:
                if i - mod_map[mod] > 1:
                    return True
            else:
                mod_map[mod] = i

        return False

    # My approach
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        """
            Time complexity -> O(n^3)
        """
        nums_size = len(nums)
        if nums_size < 2:
            return False

        wind_size = 2

        while wind_size <= nums_size:
            wind_start = 0
            wind_end = wind_start + wind_size - 1

            while wind_end < nums_size:
                wind_sum = sum(nums[wind_start:wind_end + 1])

                if wind_sum % k == 0:
                    return True

                wind_start += 1
                wind_end += 1

            wind_size += 1

        return False



