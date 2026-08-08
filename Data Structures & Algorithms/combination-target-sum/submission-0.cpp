class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtracking(nums, target, 0, temp, 0);
        return res;
    }

    void backtracking(vector<int>& nums, int target, int i, vector<int>& temp, int sum){
        if(sum == target){
            res.push_back(temp);
            return;
        }

        if(sum > target) return;
        if(i == nums.size()) return;

        // include the current number
        temp.push_back(nums[i]);
        backtracking(nums, target, i, temp, sum+nums[i]);

        // remove the number and move on and dont include this number anymore
        temp.pop_back();
        backtracking(nums, target, i+1, temp, sum);
    }
};
