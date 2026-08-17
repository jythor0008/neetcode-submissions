class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // if we traverse the edges one by one and add the edge, we are able to tell if there is a cycle immediately. how ? if i find() the vertices and they already have same parent - then this edge is a duplicate one! 
        int n = edges.size() + 1;
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        vector<int> res;
        for(vector<int>& edge : edges){
            int a = edge[0], b = edge[1];
            if(find(a) == find(b)) res = edge;
            else uf(a, b);
        }

        return res;
    }

    int find(int a){
        while( a != parent[a]){
            parent[a] = parent[parent[a]]; // flatten the tree dynamically
            a = parent[a];
        }

        return a;
    }

    void uf(int a, int b){
        // find the parents of a and b and check if they are the same
        a = find(a); b = find(b);
        if(rank[a] > rank[b]){
            rank[a] += rank[b];
            parent[b] = a;
        } else {
            rank[b] += rank[a];
            parent[a] = b;
        }
    }
};
