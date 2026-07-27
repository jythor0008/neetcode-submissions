class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int& num : nums){
            s.insert(num);
        }

        int res = 0;
        for(const int& num : s){
            // go to the smallest number and iterate from there
            if(!s.count(num-1)){
                // this is the smallest number oredi
                int idx = 1;
                while(s.count(num + idx)){
                    idx++;
                }

                res = max(res, idx);
            }
        }
        return res;
    }
};
