class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtracking(candidates, target, 0, temp, 0);
        return res;
        
    }

    void backtracking(vector<int>& candidates, int target, int i, vector<int>& temp, int sum){
        if(sum == target){
            res.push_back(temp);
            return;
        }

        if(sum > target || i == candidates.size()) return;

        // include it
        temp.push_back(candidates[i]);
        backtracking(candidates, target, i+1, temp, sum + candidates[i]);
        temp.pop_back();

        // dont include it
        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        backtracking(candidates, target, i+1, temp, sum);
    }
};
