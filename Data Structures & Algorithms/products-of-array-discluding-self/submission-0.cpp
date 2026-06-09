class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // product of prefix and postfix
        int size = nums.size();
        vector<int> res(size, 1);
        // Lets do prefix first
        int product = 1;
        for(int i = 1; i < size; i++ ){
            product*=nums[i-1];
            res[i] = product;
        }
        product = 1;
        for(int i = size - 2; i >= 0; i--){
            product *= nums[i+1];
            res[i] *= product;
        }
        return res;
    }
};
