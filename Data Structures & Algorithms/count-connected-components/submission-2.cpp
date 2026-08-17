class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        // this should be a DSU question, 
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int res = n;
        // loop through each edge, we try to find the parent of each edge and union them together. Each union we will decrease number of graph by 1         
        for(vector<int>& edge : edges){
            if(find(edge[0]) != find(edge[1])){
                unionfunc(edge[0], edge[1]);
                res--;
            } 
        }

        return res;
    }

    int find(int a){
        while(a != parent[a]){
            parent[a] = parent[parent[a]];
            a = parent[a];
        }

        return a;
    }


    void unionfunc(int a, int b){
        a = find(a);
        b = find(b);
        if(rank[a] > rank[b]){
            rank[a] += rank[b];
            parent[b] = parent[a];
        } else {
            rank[b] += rank[a];
            parent[a] = parent[b];
        }
    }
};
