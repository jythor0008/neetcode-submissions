class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int size = heights.size();
        int res = 0;
        for(int i=0; i<size; i++){
            int startIdx = i;
            while(!st.empty() && st.top().second > heights[i]){
                // pop the top value and calculate the area
                int curArea = (i - st.top().first) * st.top().second;
                res = max(res, curArea);
                startIdx = st.top().first;
                st.pop();
            }
            st.push({startIdx, heights[i]});
        }

        while(!st.empty()){
            int curArea = (size - st.top().first) * st.top().second;
            res = max(res, curArea);
            st.pop();
        }

        return res;
    }
};
