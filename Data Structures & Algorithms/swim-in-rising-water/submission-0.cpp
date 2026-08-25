class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // lowkey similar to a greedy kind of question, i can only visit nodes that are my neighbors, i will always try to take any available path until i can reach n-1, n-1
        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int time = 0;
        minHeap.push({grid[0][0], 0, 0}); // push {height, i, j}.
        visited[0][0] = true;

        vector<vector<int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        // We will loop minheap to extract cheapest path, and then see if we can swim to it. If we cant, t will be set to that value
        while(!minHeap.empty()){
            vector<int> cur = minHeap.top(); minHeap.pop();
            int height = cur[0], i = cur[1], j = cur[2];
            time = max(time, height);
            if(i == n-1 && j == i) return time;

            // loop through the neighbors and add unvisited ones in
            for(vector<int>& dir : dirs)  {
                int newi = i + dir[0];
                int newj = j + dir[1];
                if(newi < 0 || newj < 0 || newi == n || newj == n || visited[newi][newj]) continue;

                visited[newi][newj] = true;
                minHeap.push({grid[newi][newj], newi, newj});
            }
        }

        return -1;
    }
};
