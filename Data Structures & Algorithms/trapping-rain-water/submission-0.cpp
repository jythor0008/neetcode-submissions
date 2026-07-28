class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0;
        int leftMax = height[l], rightMax = height[r];
        while(l<r){
            // first find the limiting pillar
            if(leftMax < rightMax){
                // same for below condition as well, basially logic is the "next" spot can only contain at most height[x] water - away ground below it, min 0
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
