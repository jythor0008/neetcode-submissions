class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;

        // To determine if its square 1 4 7, we can make use of (y % 3 ) * 3
        // To determine if its 0 1 2 we can make use of x % 3
        unordered_map<int, unordered_set<char>> sq;

        for(int i=0; i<9; i++){
            for(int j = 0; j<9; j++){
                char cur = board[i][j];
                if(cur == '.') continue;
                else {
                    if(cols[j].count(cur) || rows[i].count(cur)) return false;
                    // calculate the square numebr
                    int square = (j/3)*3 + (i/3);
                    if(sq[square].count(cur)) return false;

                    // Register everything
                    cols[j].insert(cur);
                    rows[i].insert(cur);
                    sq[square].insert(cur);
                }
            }
        }
        return true;
    }
};