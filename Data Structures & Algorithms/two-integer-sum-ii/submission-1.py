class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers)-1
        while(l < r):
            cur = numbers[l] + numbers[r]
            if cur == target:
                return [l+1, r+1]

            if cur > target:
                r -= 1
            else:
                l += 1

        