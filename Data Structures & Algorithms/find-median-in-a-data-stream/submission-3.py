class MedianFinder:

    def __init__(self):
        self.first = [] #maxheap
        self.second = [] #minheap

    def addNum(self, num: int) -> None:
        if not self.first:
            heapq.heappush(self.first, -num)
            return

        if num < -self.first[0]:
            heapq.heappush(self.first, -num)
            if len(self.first) - len(self.second) > 1:
                heapq.heappush(self.second, -heapq.heappop(self.first))
        else:
            heapq.heappush(self.second, num)
            if len(self.second) - len(self.first) > 1:
                heapq.heappush(self.first, -heapq.heappop(self.second))


    def findMedian(self) -> float:
        if len(self.first) == len(self.second):
            return (-self.first[0] + self.second[0])/2
        
        if len(self.first) > len(self.second):
            return -self.first[0]
        
        return self.second[0]
        
        