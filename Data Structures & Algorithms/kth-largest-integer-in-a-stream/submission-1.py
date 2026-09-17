class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        # keep a minheap
        # Whenever smth come in, we can insert and pop insert and pop
        # At the end we will be left with the k elements largest
        # At the top that is the one we want
        self.minheap = []
        self.k = k
        for num in nums:
            heapq.heappush(self.minheap, num)
            if len(self.minheap) > k:
                heapq.heappop(self.minheap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minheap, val)
        if len(self.minheap) > self.k:
            heapq.heappop(self.minheap)

        return self.minheap[0]
        
