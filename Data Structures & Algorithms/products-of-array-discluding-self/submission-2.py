class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        n = len(nums)
        res = [1] * n
        # do prefix sum excluding self from left to right
        for i in range(n):
            res[i] *= product
            product *= nums[i]
        
        product = 1
        for i in range(n-1, -1, -1):
            res[i] *= product
            product *= nums[i]
        return res 

