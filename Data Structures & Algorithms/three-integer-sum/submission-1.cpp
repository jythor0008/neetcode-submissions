class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) break; // If the number is positive, it can never form 0 with numbers after it because we already sorted it
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicated numbers because we will just get duplicated triples..

            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l < r && nums[l] == nums[l-1]) l++; // Skip the same "l" value because it will just result in the same duplicates again 
                    while(l < r && nums[r] == nums[r+1]) r--; // Skip the same "l" value because it will just result in the same duplicates again 
                } else if(sum > 0){
                    r--;
                } else l++;
            }
        }
        return res;
    }
};
