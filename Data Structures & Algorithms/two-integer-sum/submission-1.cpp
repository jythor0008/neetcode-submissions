class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // I need to check if the corresponding number exists
        unordered_map<int, int> hm;
        for(int i=0; i<nums.size(); i++){
            int other = target - nums[i];
            if(hm.count(other)){
                return {hm[other], i};
            }
            hm[nums[i]] = i;
        }
        return {};

    }
};
