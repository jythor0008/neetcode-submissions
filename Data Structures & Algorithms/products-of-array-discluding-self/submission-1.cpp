class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 1);

        // Start with one loop assigning the value to the product sum of all its prefix
        int product = 1;
        for(int i=1; i<size; i++){
            product *= nums[i-1];
            res[i] = product;
        }

        product = 1;
        for(int i=size-2; i>=0; i--){
            product *= nums[i+1];
            res[i] *= product;
        }

        return res;
    }
};
