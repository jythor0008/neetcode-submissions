class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(nums, 0, temp);
        return res;
        
    }

    void dfs(vector<int>& nums, int i, vector<int>& temp){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        // include it
        temp.push_back(nums[i]);
        dfs(nums, i+1, temp);
        temp.pop_back();

        // dont include it, and dont repeat any past numbers
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        dfs(nums, i+1, temp);
    }
};
