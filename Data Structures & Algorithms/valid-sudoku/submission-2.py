class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        sq = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue
                
                # check if current number exist in row col sq alr
                num = int(board[i][j])
                idx = (i//3 * 3)+ j//3
                if num in row[i] or num in col[j] or num in sq[idx]:
                    return False

                row[i].add(num)
                col[j].add(num)
                sq[idx].add(num)
        
        return True
