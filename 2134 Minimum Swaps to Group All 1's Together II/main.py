class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        N = len(nums)
        total_ones = 0
        for i in nums:
            if i == 1:
                total_ones += 1

        l=0
        max_win_one = win_ones = 0

        for r in range(2*N):
            if nums[r % N]:
                win_ones += 1

            # Window size should be equal to total ones in nums
            if r-l+1 > total_ones:
                win_ones -= nums[l % N]
                l += 1
            max_win_one = max(max_win_one, win_ones)


        return total_ones - max_win_one
