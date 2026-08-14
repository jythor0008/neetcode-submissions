class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q;
        int row = grid.size(); int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }

                if(grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1},
        };

        // q contains rotten oranges
        // we will try to rot each neighbors until all fresh ones are rotten
        if(!fresh) return 0;
        int time = 0;
        while(!q.empty()){

            int size = q.size();
            for(int i=0; i<size; i++){
                auto [x, y] = q.front(); q.pop();

                for(auto [dx, dy] : dir){
                    int nx = dx + x, ny = dy + y;
                    if(nx < 0 || ny < 0 || nx == row || ny == col || grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }

            }
            time++;
            if(!fresh) return time;
        }

        return -1;

    }
};
