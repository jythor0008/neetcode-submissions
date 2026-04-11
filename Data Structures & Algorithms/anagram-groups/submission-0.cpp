class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        for(string& str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hm[temp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto& [k, v] : hm) {
            res.push_back(v);
        }
        return res;
    }
};
