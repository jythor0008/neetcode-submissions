class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // one method would be to just traverse everything and see if can reach all.
        // and also no cycle!

        unordered_set<int> visited;
        queue<int> q;
        unordered_map<int, vector<int>> adjList;
        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        bool nocycle = dfs(0, 0,adjList, visited);

        return nocycle && visited.size() == n;
    }

    bool dfs(int cur, int prev, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited){
        if(visited.count(cur)) return false;

        visited.insert(cur);
        for(int& n : adjList[cur]){
            if(n == prev) continue;
            if(!dfs(n, cur, adjList, visited)) return false;
        }

        return true;
    }
};