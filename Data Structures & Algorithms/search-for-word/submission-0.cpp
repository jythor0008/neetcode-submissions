class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // loop through the board, if meet starting char correct, do dfs from there 4 direction with visited set
        int row = board.size(), col = board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> visited(row, vector<int>(col, 0));
                    if(dfs(board, i, j, word, 0, visited)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<int>>& visited){
        if(idx == word.size()) return true;
        int row = board.size(), col = board[0].size();
        if(i < 0 || j < 0 || i == row || j == col || visited[i][j] || board[i][j] != word[idx]) return false;

        visited[i][j] = 1;

        // search all four directions
        bool res = dfs(board, i+1, j, word, idx+1, visited) || 
        dfs(board, i-1, j, word, idx+1, visited) || 
        dfs(board, i, j+1, word, idx+1, visited) || 
        dfs(board, i, j-1, word, idx+1, visited);
        visited[i][j] = 0;
        return res;
    }
};
