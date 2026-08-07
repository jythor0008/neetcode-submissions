class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // minheap of points
        struct comparator{
            bool operator()(const vector<int>& a, const vector<int>& b){
                float xa = a[0] - 0; xa *= xa;
                float ya = a[1] - 0; ya *= ya;
                float distA = sqrt(xa + ya);

                float xb = b[0] - 0; xb *= xb;
                float yb = b[1] - 0; yb *= yb;
                float distB = sqrt(xb + yb);

                return distA > distB;
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, comparator> minHeap;

        for(auto point : points){
            minHeap.push(point);
        }

        vector<vector<int>> res;
        while(res.size() < k){
            res.push_back(minHeap.top()); minHeap.pop();
        }

        return res;
    }   
};
