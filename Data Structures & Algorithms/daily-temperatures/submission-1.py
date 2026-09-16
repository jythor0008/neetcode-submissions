class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # monotonic decreasing stack
        # Whenever i find a new hotter temperature, i pop the previous day and i update the result array
        stack = []
        res = [0] * len(temperatures)
        for i, temp in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < temp:
                colder_day = stack.pop()
                res[colder_day] = i - colder_day
            
            stack.append(i)
        
        return res