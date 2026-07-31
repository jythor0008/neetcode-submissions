class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            // Try to see if we can eat finish pile in h hours if we eat mid bananas per hour
            int curTime = 0;
            for(int& pile : piles){
                int time = (pile + mid - 1) / mid;
                curTime += time; 
            }
            if(curTime > h) l = mid + 1;
            else{
                res = min(res, mid);
                r = mid - 1;
            } 
        }
        return res;
    }
};
