class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(0, 0, n, s);
        return res;
        
    }

    void dfs(int open, int close, int n, string& temp){
        if(open == close && n == open){
            res.push_back(temp);
            return;
        }

        if(open > n) return;

        if(close > open) return;

        // add a open
        temp += "(";
        dfs(open + 1, close, n, temp);
        temp.pop_back();

        // add a close
        temp += ")";
        dfs(open, close+1, n, temp);
        temp.pop_back();
    }
};
