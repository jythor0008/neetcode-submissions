class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])

        q = deque()
        fresh = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    fresh += 1

                if grid[i][j] == 2:
                    q.append((i, j))

        time = 0
        dir = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        print(fresh)
        while q and fresh:
            size = len(q)
            for _ in range(size):
                i, j = q.popleft()
                for di, dj in dir:
                    ni, nj = i+di, j+dj
                    if ni < 0 or nj < 0 or ni == row or nj == col:
                        continue

                    if grid[ni][nj] != 1:
                        continue
                    fresh -= 1
                    grid[ni][nj] = 2
                    q.append((ni, nj))

            time += 1

        return time if not fresh else -1 