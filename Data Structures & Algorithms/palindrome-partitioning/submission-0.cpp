class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        // brute force
        // try every sequence and see if its a palindrome
        vector<string> temp;
        dfs(s, 0, temp);
        return res;
    }

    void dfs(string& s, int i, vector<string>& temp){
        if(i == s.size()){
            res.push_back(temp);
            return;
        }

        // Loop through next few strings, try to make substrings starting from i to j
        for(int j = i; j<s.size(); j++){
            if(isPalin(s, i, j)){
                temp.push_back(s.substr(i, j-i+1));
                dfs(s, j+1, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalin(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};
