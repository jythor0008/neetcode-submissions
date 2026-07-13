class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hm;
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hm[key].push_back(str);
        }

        for(auto& [k, v] : hm){
            res.push_back(v);
        }

        return res;

    }
};
