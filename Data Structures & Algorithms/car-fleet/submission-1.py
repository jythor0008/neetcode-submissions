class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        stack = []
        for pos, spd in cars:
            time_needed = float(target - pos) / float(spd)
            if not stack or stack[-1] < time_needed:
                stack.append(time_needed)


        return len(stack)