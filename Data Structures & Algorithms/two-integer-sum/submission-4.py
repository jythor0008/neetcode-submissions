class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hm = {}
        for i in range(len(nums)):
            need = target - nums[i]
            if need in hm.keys():
                return [hm[need], i]

            hm[nums[i]] = i

        return []