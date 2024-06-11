from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # Step 1: Create a frequency count array for elements in arr1
        max_val = max(arr1)
        count_arr = [0] * (max_val + 1)
        for num in arr1:
            count_arr[num] += 1

        # Step 2: Populate the result array with elements in arr2
        result = []
        for num in arr2:
            while count_arr[num] > 0:
                result.append(num)
                count_arr[num] -= 1

        # Step 3: Append remaining elements from arr1 (not in arr2) sorted in ascending order
        for num in range(max_val + 1):
            while count_arr[num] > 0:
                result.append(num)
                count_arr[num] -= 1

        return result
