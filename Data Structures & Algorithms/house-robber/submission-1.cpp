class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int house1 = nums[0], house2 = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            int steal = house1 + nums[i];
            house1 = house2;
            house2 = max(steal, house2);
        }

        return max(house1, house2);

    }
};
