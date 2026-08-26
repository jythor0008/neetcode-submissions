class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Create topo sort order and return any valid combination
        vector<unordered_set<char>> adjList(26);
        unordered_map<char, int> inDeg;
        // Get all the valid word that exist in this qn scope
        for(string& word : words){
            for(char& c : word){
                inDeg[c] = 0;
            }
        }

        // Form the adjlist
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int idx = 0;
            bool found = false;
            while(idx < w1.size() && idx < w2.size()){
                char from = w1[idx], to = w2[idx];
                if(from != to){
                    if(!adjList[from - 'a'].count(to)){
                        adjList[from - 'a'].insert(to);
                        inDeg[to]++;
                    }
                    found = true;
                    break;
                }
        
                idx++;
            }

            if(!found && w1.size() > w2.size()) return ""; // edge case where we have "abcde", "abc" --> invalid!
        }

        queue<char> q;
        for(auto [c, cnt] : inDeg){
            if(cnt == 0) q.push(c);
        }

        string res = "";
        while(!q.empty()){
            char cur = q.front(); q.pop();
            res += cur;

            for(char c : adjList[cur - 'a']){
                inDeg[c]--;
                if(inDeg[c] == 0) q.push(c);
            }
        }
        return res.size() == inDeg.size() ? res : "";
    }
};
