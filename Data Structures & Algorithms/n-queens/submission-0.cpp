class Solution {
vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(n, board, 0);
        return res;
    }

    void dfs(int n, vector<string>& board, int i){
        if(i == n) {
            res.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(valid(board, i, j, n)){
                // we can try placing a queen here 
                board[i][j] = 'Q';
                dfs(n, board, i+1);

                board[i][j] = '.'; // undo it for next iteration
            }
        }
    }

    bool valid(vector<string>& board, int i, int j, int n){
        // check upper left diagonal from curent coord
        for(int row = i-1, col = j-1; row >= 0 && col >= 0; row--, col--){
            if(board[row][col] == 'Q') return false;
        }
        // check upper right diagonal from curent coord
        for(int row = i-1, col = j+1; row >= 0 && col < n; row--, col++){
            if(board[row][col] == 'Q') return false;
        }

        // check directly above
        for(int row = i-1; row >= 0; row--){
            if(board[row][j] == 'Q') return false;
        }

        return true;
    }
};
