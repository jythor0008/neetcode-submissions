class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // theres a few methods here -> here we can do binary search or we can do searching from top right corner first
        // 1. Lets first do binary search like we're meant to
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows - 1;
        // find which row the number belongs to
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target && matrix[mid][cols-1] >= target ){

                // search within this row
                int newl = 0, newr = cols-1;
                while(newl <= newr) {
                    int newmid = newl + (newr - newl)/2;
                    if(matrix[mid][newmid] == target){
                        return true;
                    }
                    else if(matrix[mid][newmid] > target) newr = newmid - 1;
                    else newl = newmid + 1;
                }

                return false;

            } else if(matrix[mid][cols-1] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
