class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        n, m = len(nums1), len(nums2)
        total = n + m
        mid_elements = total//2
        l,r = 0, min(mid_elements, n)
        while(l<=r):
            num_A = l + (r-l)//2
            num_B = mid_elements - num_A

            a_left = nums1[num_A-1] if num_A - 1 >= 0 else float('-inf')
            b_left = nums2[num_B-1] if num_B - 1 >= 0 else float('-inf')
            a_right = nums1[num_A] if num_A < n else float('inf')
            b_right = nums2[num_B] if num_B < m else float('inf')

            if a_left <= b_right and b_left <= a_right:
                if total % 2:
                    return min(a_right, b_right)
                
                return (max(a_left, b_left) + min(a_right, b_right))/2
            
            if a_left > b_right:
                r = num_A - 1
            else:
                l = num_A + 1
        
        return 0

