class Solution {
    vector<int> parent;
    vector<int> rank;
public:

    int find(int a){
        while(a != parent[a]){
            parent[a] = parent[parent[a]];
            a = parent[a];
        }

        return a;
    }

    void Union(int a, int b){
        int pa = find(a), pb = find(b);
        if(rank[pa] > rank[pb]){
            rank[pa] += rank[pb];
            parent[pb] = pa;
        } else {
            rank[pb] += rank[pa];
            parent[pa] = pb;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        parent = vector<int>(size);
        rank = vector<int>(size, 1);


        // find distance to all points and store them inside a priority queue
        // I think we can just use kruskal algo
        vector<vector<int>> edges;
        for(int i=0; i<size; i++){
            parent[i] = i;
            for(int j=i+1; j<size; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int res = 0;
        for(vector<int>& edge : edges){
            if(find(edge[1]) == find(edge[2])) continue;
            Union(edge[1], edge[2]);
            res += edge[0];
        }

        return res;

    }
};
