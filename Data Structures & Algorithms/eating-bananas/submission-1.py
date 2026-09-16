class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # Binary search on eating speed
        l, r = 1, max(piles)
        res = float('inf')
        while(l <= r):
            eat_speed = l + (r-l)//2
            # See if can eat finish using this speed
            total_time = 0
            possible = True
            for pile in piles:
                total_time += (pile + eat_speed-1) // eat_speed
                # break if at anypoint not possible
                if total_time > h:
                    possible = False
                    break

            if possible:
                res = min(res, eat_speed)
                r = eat_speed - 1
            else:
                l = eat_speed + 1
        
        return res


