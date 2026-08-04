class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        // slow and fast are now pointing to the same index, which means there is a cycle
        // To find the cycle, start from the beginning and trace until they meet.
        int temp = nums[0];
        while(true){
            if(temp == slow) return temp;
            temp = nums[temp];
            slow = nums[slow];
        }

        return -1;
    }
};
