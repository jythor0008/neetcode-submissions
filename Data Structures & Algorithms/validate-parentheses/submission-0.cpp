class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> hm = {
            {')', '(' },
            {'}', '{' },
            {']', '[' }
        };
        for(char& c : s){
            if(hm.count(c)){
                if(st.empty() || st.top() != hm[c]) return false;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
        
    }
};
