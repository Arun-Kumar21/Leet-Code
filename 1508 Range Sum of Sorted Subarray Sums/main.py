class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        mod = 10**9 + 7 
        
        arr = [] 
        
        for i in range(len(nums)):
            sum = 0 
            for j in range(i, len(nums)): 
                sum += nums[j] 
                arr.append(sum)
        
        arr.sort()
        
        res = 0
        for i in range(left-1, right):
            res += arr[i]
        
        return res % mod
