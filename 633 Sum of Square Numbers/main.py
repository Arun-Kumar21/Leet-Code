import math


class Solution:
    # Time complexity - O(n**1/2 log N + N**1/2)
    def binary_search(self, element, sorted_arr) -> bool:
        l, h = 0, len(sorted_arr) - 1  # h should be the last index

        while l <= h:
            mid = l + (h - l) // 2  # use integer division
            if sorted_arr[mid] == element:
                return True
            elif sorted_arr[mid] < element:
                l = mid + 1
            else:
                h = mid - 1

        return False

    def judgeSquareSum(self, c: int) -> bool:
        sq_arr = []

        for i in range(int(math.sqrt(c)) + 1):  # convert to int and include upper bound
            sq_arr.append(i ** 2)

        for j in sq_arr:
            if self.binary_search(c - j, sq_arr):  # use self to call the method
                return True

        return False


class Solution2:
    # Two pointer approach - O(C**1/2)
    def judgeSquareSum(self, c: int) -> bool:
        sq_arr = []

        for i in range(int(math.sqrt(c))+1):
            sq_arr.append(i**2)

        l, h = 0, len(sq_arr)-1

        while l <= h:
            curr_sum = sq_arr[l]+sq_arr[h]
            if curr_sum == c:
                return True
            elif curr_sum < c:
                l += 1
            else:
                h -= 1

        return False

