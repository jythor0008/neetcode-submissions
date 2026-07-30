class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0);
        // monotonic decreasing stack
        stack<int> st;
        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int idx = st.top(); st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};
