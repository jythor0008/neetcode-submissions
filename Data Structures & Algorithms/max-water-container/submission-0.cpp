class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int res = 0;
        while(l < r){
            int leftpillar = heights[l], rightpillar= heights[r];
            int area = min(leftpillar, rightpillar) * (r - l);
            res = max(res, area);
            if(leftpillar < rightpillar) l++;
            else r--;
        }
        return res;
    }
};
