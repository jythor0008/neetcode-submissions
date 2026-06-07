class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        vector<vector<int>> counter(size+1);
        for(auto [num, cnt] : freq){
            counter[cnt].push_back(num);
        }

        vector<int> res;
        int i = size;
        while( i >= 0){
            if(counter[i].empty()) i--;
            else {
                res.push_back(counter[i].back());
                counter[i].pop_back();
                k--;
            }

            if(k == 0) break;
        }

        return res;
    }
};
