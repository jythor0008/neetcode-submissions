class MinStack {

    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        } else {
            int prevMin = st.top().second;
            st.push({val, min(val, prevMin)});
        }

    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
