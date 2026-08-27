class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 2) return min(cost[0], cost[1]);
        int n1 = cost[n-1], n2 = cost[n-2];
        int idx = n-3;
        while(idx >= 0){
            int nxt = cost[idx] + min(n1, n2);
            n1 = n2;
            n2 = nxt;
            idx--;
        }

        return min(n1, n2);
    }
};
