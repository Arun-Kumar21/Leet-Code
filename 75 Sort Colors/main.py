class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # Count the number of 0's, 1's, and 2's
        zeros = ones = twos = 0

        for num in nums:
            if num == 0:
                zeros += 1
            elif num == 1:
                ones += 1
            else:
                twos += 1

        # Modify nums in-place
        index = 0
        for _ in range(zeros):
            nums[index] = 0
            index += 1
        for _ in range(ones):
            nums[index] = 1
            index += 1
        for _ in range(twos):
            nums[index] = 2
            index += 1


    # Dutch National Flag algorithm
    '''
    class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        low, mid, high = 0, 0, len(nums) - 1

        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1

    '''