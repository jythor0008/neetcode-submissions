class KthLargest {

    struct comparator {
        bool operator()(const int& a, const int & b){
            return a > b;
        }
    };

    priority_queue<int, vector<int>, comparator> minHeap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        // i want a minheap of size k
        size = k;
        for(int &num : nums){
            minHeap.push(num);
            if(minHeap.size() > size) minHeap.pop();
        }

    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > size) minHeap.pop();
        return minHeap.top();
    }
};
