class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # lets keep a monotonic increasing stakc
        # When we meet a smaller number, we want to pop all bigger seen and update their largest rectangle that can be formed
        # stack value shall be (height, starting idx) -> when we pop somehting bigger, and before inserting the current small one, we put the idx to be starting idx of the bigger thing we seen because it can help us extend the current height backwards as well. 
        stack = []
        res = float('-inf')
        for i, height in enumerate(heights):
            idx_to_insert = i
            while stack and stack[-1][0] >= height:
                cur_height, start = stack.pop()
                # cur_height can be extended from start till height
                width = i - start
                res = max(res, cur_height * width)
                idx_to_insert = start

            stack.append((height, idx_to_insert))
        

        while stack:
            cur_height, start = stack.pop()
            # cur_height can be extended from start till end
            width = len(heights) - start
            res = max(res, cur_height * width)

        return res



