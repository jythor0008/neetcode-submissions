class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        max_heap = [-v for v in Counter(tasks).values()]

        heapq.heapify(max_heap)

        # Now i have a maxheap of all the counts, i want to loop it until im done
        cpu = 0
        q = deque()
        while max_heap or q:
            # Add any ready thing into the queue
            while q and q[0][0] == cpu:
                heapq.heappush(max_heap, q.popleft()[1])

            if max_heap:
                cur = heapq.heappop(max_heap)
                cur += 1
                if cur < 0:
                    q.append((n + cpu + 1, cur))

            cpu += 1
        
        return cpu

            
            


