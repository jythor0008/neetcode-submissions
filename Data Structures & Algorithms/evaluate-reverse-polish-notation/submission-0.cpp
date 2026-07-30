class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int first, second;
        for(string& token : tokens){
            if(token == "+" || token == "-" || token == "/" || token == "*"){
                second = st.top(); st.pop();
                first = st.top(); st.pop();
                
                if(token == "+") st.push(first + second);
                else if(token == "-") st.push(first - second);
                else if(token == "*") st.push(first * second);
                else st.push(first / second);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
