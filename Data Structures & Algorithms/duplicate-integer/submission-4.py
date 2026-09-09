class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set_ = set()
        for num in nums:
            if num in set_:
                return True
            set_.add(num)
            
        return False