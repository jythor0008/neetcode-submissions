class Solution {
public:
    int rob(vector<int>& nums) {
        // Two options. Rob first cannot rob last
        // Rob last cannot rob first
        // Repeat twice get the max result
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        // Option 1
        int house1 = nums[0];
        int house2 = max(nums[0], nums[1]);
        for(int i=2; i<n-1; i++){
            int next = max(house1+nums[i], house2);
            house1 = house2;
            house2 = next;
        }

        int option1 = max(house1, house2);

        // Option 2
        house1 = 0;
        house2 = nums[1];
        for(int i=2; i<n; i++){
            int next = max(house1+nums[i], house2);
            house1 = house2;
            house2 = next;
        }

        int option2 = max(house1, house2);
        return max(option1, option2);
    }
};
