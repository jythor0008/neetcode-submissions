class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # Do bfs from the chests
        row, col = len(grid), len(grid[0])
        q = deque()
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    q.append((i, j))

        inf = 2**31 - 1
        distance = 1
        dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while q:
            size = len(q)
            for _ in range(size):
                i, j = q.popleft()

                for di, dj in dir:
                    ni, nj = i+di, j+dj
                    if ni < 0 or nj < 0 or ni == row or nj == col:
                        continue # Invalid coord

                    if grid[ni][nj] != inf:
                        continue # not an unseen valid land

                    grid[ni][nj] = distance
                    q.append((ni, nj))

            distance += 1

