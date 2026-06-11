class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // modified 2 sum question
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = size-1;
            while(l < r){
                int total = nums[i] + nums[l] + nums[r];
                if(total == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                } else if(total > 0){
                    r--;
                } else l++;
            }
        }
        return res;
    }
};
