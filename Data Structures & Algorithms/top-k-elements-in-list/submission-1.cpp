class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int &num : nums){
            count[num]++;
        }

        int size = nums.size();
        vector<vector<int>> temp(size+1, vector<int>());
        for(auto &[k, v] : count){
            temp[v].push_back(k);
        }

        vector<int> res;
        for(int i = size; i > 0; i--){
            for(int j=0; j < temp[i].size(); j++){
                res.push_back(temp[i][j]);
                k--;
                if(k == 0) return res;
            }
        }
        return res;
    }
};
