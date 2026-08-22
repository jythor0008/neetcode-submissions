class Solution {
    vector<int> parent, rank;
public:
    int find(int node){
        int p = parent[node];
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool Union(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
            rank[pu] += rank[pv];
        } else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
        return true;

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        // This is a minimum spanning tree problem
        // Calculate all the distance, and push them as edges into a pq
        // Do union find algo to check if will add cycle. if will then skip it
        int size = points.size();
        parent.resize(size);
        rank.resize(size, 1);
        for(int i=0; i<size; i++){
            parent[i] = i;
        }
        
        vector<vector<int>> edges;
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i ,j});
            }
        }

        sort(edges.begin(), edges.end());
        int res = 0;
        for(vector<int>& edge : edges){
            int u = edge[1], v = edge[2], d = edge[0];
            if(!Union(u, v)) continue;
            res += d;
        }
        return res;
    }
};
