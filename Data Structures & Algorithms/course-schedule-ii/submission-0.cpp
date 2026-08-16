class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courses;
        unordered_map<int, int> inDeg;

        for(vector<int>& pre : prerequisites){
            int first = pre[1];
            int second = pre[0];

            courses[first].push_back(second);
            inDeg[second]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!inDeg.count(i)) q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            res.push_back(cur);

            for(int nxt : courses[cur]){
                inDeg[nxt]--;
                if(inDeg[nxt] == 0) q.push(nxt);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};
