class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // learn topo sort
        // If im not wrong its something about creating vectors of its prerquisites? so if this guy prereq is not empty i cannot do anything to do it or something, or in others words, in deg. 
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> inDeg;
        for(vector<int>& pre : prerequisites){
            int prereq = pre[1];
            int after = pre[0];
            inDeg[after]++;
            adjList[prereq].push_back(after);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(!inDeg.count(i)) q.push(i);
        }

        int complete = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int c : adjList[cur]){
                inDeg[c]--;
                if(inDeg[c] == 0) q.push(c);
            }
            complete++;
        }

        return complete == numCourses;

    }
};
