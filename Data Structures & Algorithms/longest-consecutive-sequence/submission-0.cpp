class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for(const int& num : nums){
            s.insert(num);
        }

        for(const int& num : s){
            if(!s.count(num - 1)) {
                int val = num;
                int cur = 0;
                while(s.count(val)){
                    cur++;
                    val++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
