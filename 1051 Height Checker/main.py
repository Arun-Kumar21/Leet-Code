from typing import List


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        """
            using count sort algorithm with time complexity -> O(N)
        """
        max_height = max(heights)

        count_array = [0]*(max_height+1)

        for i in heights:
            count_array[i] += 1

        for i in range(1, max_height + 1):
            count_array[i] += count_array[i - 1]

        sorted_array = [0] * len(heights)

        for i in range(len(heights) - 1, -1, -1):
            sorted_array[count_array[heights[i]] - 1] = heights[i]
            count_array[heights[i]] -= 1

        j = 0
        res = 0
        while j < len(sorted_array):
            if sorted_array[j] != heights[j]:
                res += 1
            j += 1

        return res
