class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[r]) {
                // we are in the sorted larger left half
                if(target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                // in the sorted smaller right half
                if(target <= nums[r] && target > nums[mid]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
