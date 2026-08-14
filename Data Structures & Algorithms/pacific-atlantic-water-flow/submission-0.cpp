class Solution {
    int row;
    int col;
    vector<pair<int, int>> dir;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // overall gist is start from top left and bottom right respectively, dfs on each node see which one i can mark as true
        // Find all that can link to pacific side
        // Find all that can link to atlantic side
        // Answer is the set between them!
        row = heights.size();
        col = heights[0].size();
        dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        // Start from heights[0][i] to see which ones can reach pacific
        for(int i=0; i<col; i++){
            dfs(heights, 0, i, pacific);
            dfs(heights, row-1, i, atlantic);
        }

        for(int i=0; i<row; i++){
            dfs(heights, i, 0, pacific);
            dfs(heights, i, col-1, atlantic);
        }

        vector<vector<int>> res;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean){
        // let's assume if we get here, means we mark it as can reach. Then we only branch if CAN reach others
        ocean[i][j] = true;

        for(auto [dx, dy] : dir){
            int nx = dx + i;
            int ny = dy + j;
            if(nx < 0 || ny < 0 || nx == row || ny == col) continue;
            // We only want grids that are hgher or lower than current
            if(!ocean[nx][ny] && heights[nx][ny] >= heights[i][j]) dfs(heights, nx, ny, ocean);
        }

    }
};
