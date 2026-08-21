class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());
        unordered_map<string, vector<string>> adjList;
        
        for(auto& ticket : tickets){
            adjList[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res;
        dfs(adjList, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<string, vector<string>>& adjList, const string& cur, vector<string>& res){

        while(!adjList[cur].empty()){
            string next = adjList[cur].back(); adjList[cur].pop_back();
            dfs(adjList, next, res);
        }

        res.push_back(cur);

    }
};
