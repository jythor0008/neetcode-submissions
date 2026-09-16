class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))
        

    def get(self, key: str, timestamp: int) -> str:
        vals = self.map[key]
        if not vals:
            return ""

        l,r = 0, len(vals)-1
        res = ""
        while(l<=r):
            mid = l + (r-l)//2
            if vals[mid][0] <= timestamp:
                res = vals[mid][1]
                l = mid + 1
            else:
                r = mid - 1

        return res
        
