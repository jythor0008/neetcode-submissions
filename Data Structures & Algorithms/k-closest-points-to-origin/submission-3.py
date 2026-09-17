class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # use a maxheap, streaming insert everything maintain a size of k
        # Once done we can pop all the points and thats the result
        max_heap = []
        for x, y in points:
            distance = math.sqrt(x**2 + y**2)
            heapq.heappush(max_heap, (-distance, x, y))

            if len(max_heap) > k:
                heapq.heappop(max_heap)

        res = []
        while max_heap:
            _, x, y = heapq.heappop(max_heap)
            res.append((x, y))

        return res
        