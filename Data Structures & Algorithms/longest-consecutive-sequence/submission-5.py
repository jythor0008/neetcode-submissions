class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # first insert everything into a set
        # Traverse the set and start from the smallest number possible
        s = set(nums)
        res = 0
        
        for num in s:
            if num-1 not in s:
                i = 0
                while num+i in s:
                    i+=1
                
                res = max(res, i)

        return res