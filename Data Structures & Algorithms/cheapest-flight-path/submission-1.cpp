class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // shortest distance within k hops, i think we can honestly just use bellman ford algo
        // bellman ford also says that if we loop n - 1 time, we can get shortest distance from src to every node because the longest possible path is n-1 edge! So if we can reach in k edge, then we have the current shortest solution
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        for(int i=0; i<k+1; i++){
            // relax every edge k+1 times, because k stops -> means k+1 edges
            vector<int> temp = dist;
            for(vector<int>& flight : flights){
                int from = flight[0], to = flight[1], cost = flight[2];
                if(dist[from] != INT_MAX && dist[from] + cost < temp[to]) temp[to] = dist[from] + cost;
            }

            swap(temp, dist);
        }

        return dist[dst] == INT_MAX? -1 : dist[dst];
    }
};
