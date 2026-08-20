class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // lets try bellman ford now since we mastered djikstra
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        for(int i=1; i<=n; i++){
            // update the distance n-1 times
            bool updated = false;
            for(vector<int>& time : times){
                int u = time[0], v = time[1], d = time[2];
                if(dist[u] != INT_MAX && dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                    updated = true;
                }

            }

            if(!updated) break;
        }

        // now we loop through dist to see if anyone not visited
        int res = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }

        return res;
    }
};
