class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // make a max heap so we know which are the heaviest stones right away
        priority_queue<int> maxHeap;
        for(int& stone : stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() >= 2){
            int first = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();
            if(first == second) continue;

            maxHeap.push(abs(first - second));
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
