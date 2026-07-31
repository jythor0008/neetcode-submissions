class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) // means we are the larger side of the array and should search to the right
                l = mid + 1;
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};
