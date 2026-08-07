class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // maxheap of points
        struct comparator{
            bool operator()(const vector<int>& a, const vector<int>& b){
                float xa = a[0] - 0; xa *= xa;
                float ya = a[1] - 0; ya *= ya;
                float distA = sqrt(xa + ya);

                float xb = b[0] - 0; xb *= xb;
                float yb = b[1] - 0; yb *= yb;
                float distB = sqrt(xb + yb);

                return distA < distB;
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, comparator> maxHeap;

        for(auto point : points){
            maxHeap.push(point);
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top()); maxHeap.pop();
        }

        return res;
    }   
};
