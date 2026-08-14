class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // find all treasure chest
        queue<pair<int, int>> q;
        int row = grid.size(), col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<pair<int, int>> dir = {
            {0, 1},
            {0, -1},
            {1,0},
            {-1, 0}
        };

        while(!q.empty()){
            // update its neighbours
            auto [i,j] = q.front(); q.pop();
            for(auto [x, y] : dir){
                int newi = i + x;
                int newj = j + y;

                // Check if its valid grid
                if(newi < 0 || newj < 0 || newi == row || newj == col) continue;

                int val = grid[newi][newj];
                if(val == -1 || val != INT_MAX) continue; // water or it already been updated before

                // update grid and queue it
                grid[newi][newj] = grid[i][j] + 1;
                q.push({newi, newj});
            }
        }

    }
};
