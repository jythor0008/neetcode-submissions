class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>> > adjList(n+1);
        for(vector<int>& time : times){
            adjList[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> >  minHeap;  // {d, v} so that minheap prioritise shortest distance -> greedy!
        minHeap.push({0, k});
        dist[k] = 0;

        unordered_set<int> visited;
        int res = 0;

        while(!minHeap.empty()){
            pair<int, int> cur = minHeap.top(); minHeap.pop();
            int d = cur.first;
            int u = cur.second;

            if(d > dist[u]) continue;
            visited.insert(u);
            res = d;

            // relax the neighbors
            for(pair<int, int>& n : adjList[u]){
                int v = n.first;
                int cost = n.second;
                if(d + cost < dist[v]){
                    dist[v] = d + cost;
                    minHeap.push({d + cost, v});
                }
            }
        }

        return visited.size() == n ? res : -1;
    }
};
