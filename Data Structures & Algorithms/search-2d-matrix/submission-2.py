class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROW, COL = len(matrix), len(matrix[0])
        i, j = 0, COL-1

        while i >= 0 and j >= 0 and i < ROW and j < COL:
            if matrix[i][j] == target:
                return True

            if matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        
        return False