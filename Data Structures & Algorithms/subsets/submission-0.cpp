class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtracking(nums, 0, temp);
        return res;
    }

    void backtracking (vector<int> &nums, int i, vector<int>& temp) {
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        // dont include it
        backtracking(nums, i+1, temp);

        // include it
        temp.push_back(nums[i]);
        backtracking(nums, i+1, temp);
        temp.pop_back();
    }
};
