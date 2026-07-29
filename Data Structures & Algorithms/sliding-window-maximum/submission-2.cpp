class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // kind of like a monotonic queue ?
        vector<int> res;
        deque<int> q;
        int l = 0;
        for(int r=0; r<nums.size(); r++){
            while(!q.empty() && nums[q.back()] < nums[r]) q.pop_back();
            q.push_back(r);

            if(r-l+1 == k){
                res.push_back(nums[q.front()]);
                // time to shrink
                if(q.front() == l) q.pop_front();
                l++;
            }
        }
        return res;


    }
};
