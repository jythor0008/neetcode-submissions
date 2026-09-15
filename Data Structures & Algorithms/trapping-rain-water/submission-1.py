class Solution:
    def trap(self, height: List[int]) -> int:
        l=0
        r = len(height)-1
        minLeft = height[l]
        minRight = height[r]
        water = 0
        while(l<=r):
            if minLeft < minRight:
                minLeft = max(minLeft, height[l])
                water += minLeft - height[l]
                l += 1
            else:
                minRight = max(minRight, height[r])
                water += minRight - height[r]
                r -= 1
        
        return water
