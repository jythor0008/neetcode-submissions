class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        # keep a monotonic decreasing queue
        res = []
        l = 0
        for r, val in enumerate(nums):
            while q and nums[q[-1]] < val:
                q.pop()
            
            q.append(r)

            if r-l+1 == k:
                res.append(nums[q[0]])
                l += 1
                
                if q and q[0] < l:
                    q.popleft()

        return res


                