class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count number of similar tasks
        vector<int> cnt(26, 0);
        for(char& c : tasks){
            cnt[c-'A']++;
        }

        priority_queue<int> maxHeap;
        for(int& i : cnt){
            if(i > 0) maxHeap.push(i);
        }

        queue<pair<int, int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            // Put all ready into max heap
            while(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first); q.pop();
            }

            if(!maxHeap.empty()){
                // schedule the top task first and see push into ready queue if any
                int taskCnt = maxHeap.top(); maxHeap.pop();
                taskCnt--;
                if(taskCnt > 0) q.push({taskCnt, time + n + 1});
            }

            // increase time
            time++;
        }

        return time;

    }
};
