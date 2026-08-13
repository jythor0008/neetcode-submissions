class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations = {{nums[0]}};


        for(int i=1; i<nums.size(); i++){
            // Loop through every number
            vector<vector<int>> newPerms;
            for(auto &perm : permutations){
                // For Each number, we look through all existing permutations
                for(int j=0; j<=perm.size(); j++){
                    // Insert at every position of old permutations to make a new permutation
                    vector<int> temp = perm;
                    temp.insert(temp.begin() + j, nums[i]);
                    newPerms.push_back(temp);
                }
            }
            permutations = newPerms;
        }

        return permutations;
    }
};
