class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while(l<=r):
            mid = l + (r-l)//2

            left = nums[mid-1] if mid > 0 else float("inf")
            right = nums[mid+1] if mid < len(nums)-1 else float("inf")
            if nums[mid] < left and nums[mid] < right:
                return nums[mid]
            
            # Current val is larger than right side, means right half is what we want
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid - 1

        