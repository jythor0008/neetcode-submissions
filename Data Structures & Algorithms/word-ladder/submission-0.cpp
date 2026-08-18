class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_map<string, vector<string>> neigh;
        wordList.push_back(beginWord);

        // Create a map of pattern to all the words that fit the pattern
        for(string& word : wordList){
            for(int i=0; i<word.size(); i++){
                string temp = word;
                temp[i] = '*';
                neigh[temp].push_back(word);
            }
        }

        // Do BFS starting from beginWord, count the number of time we need to reach the end
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0; i<size; i++){
                string cur = q.front(); q.pop();
                if(cur == endWord) return res;
                // cur is not a key!! need the pattern so we should generate the pattern
                for(int j=0; j<cur.size(); j++){
                    string pattern = cur;
                    pattern[j] = '*';
                    for(string& n : neigh[pattern]){
                        if(visited.count(n)) continue;
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }

        }

        return 0;
    }
};
