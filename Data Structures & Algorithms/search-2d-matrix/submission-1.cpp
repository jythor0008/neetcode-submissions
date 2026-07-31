class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // theres a few methods here -> here we can do binary search or we can do searching from top right corner first
        // 2. This is the second solution, staircase search
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols-1;
        while(row >= 0 && row < rows && col >= 0 && col < cols){
            int cur = matrix[row][col];
            if(cur == target) return true;
            if(cur > target) col--;
            else row++;
        }
        return false;
    }
};
