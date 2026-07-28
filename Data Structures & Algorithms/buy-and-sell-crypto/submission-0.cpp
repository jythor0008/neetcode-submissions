class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy lowest sell highest
        int res = 0;
        int buy = INT_MAX;
        for(int& price : prices){
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};
