class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])

        def dfs(grid, i, j):
            if i < 0 or j < 0 or i == row or j == col or grid[i][j] == "0":
                return

            grid[i][j] = "0"
            dfs(grid, i+1, j)
            dfs(grid, i-1, j)
            dfs(grid, i, j+1)
            dfs(grid, i, j-1)


        res = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1":
                    res += 1
                    dfs(grid, i, j)


        return res

            