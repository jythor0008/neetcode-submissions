class Solution {
    int row;
    int col;
    vector<pair<int, int>> dir;
public:
    void solve(vector<vector<char>>& board) {
        // do dfs from the O's that are outside, change them to something else first 
        // Everything else will be X

        row = board.size(), col = board[0].size();
        dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        // Settle all row 0 and last row
        for(int i=0; i<col; i++){
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }

        for(int i=0; i<row; i++){
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i == row || j == col || board[i][j] != 'O') return;

        board[i][j] = 'A';
        for(auto [dx, dy] : dir){
            dfs(board, i+dx, j+dy);
        }
    }
};
