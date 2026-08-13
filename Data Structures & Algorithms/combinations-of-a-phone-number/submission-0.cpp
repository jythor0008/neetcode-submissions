class Solution {
vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, vector<char>> dict = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };

        string temp = "";
        dfs(digits, 0, temp, dict);
        return res;
    }

    void dfs(string& digits, int i, string& temp, unordered_map<char, vector<char>>& dict){
        if(i == digits.size()){
            res.push_back(temp);
            return;
        }

        // loop through the possible characters of the current digit and add them to temp
        for(char& c : dict[digits[i]]) {
            temp.push_back(c);
            dfs(digits, i+1, temp, dict);
            temp.pop_back();
        }

    }

};
