class WordDictionary {
    struct Node {
        unordered_map<char, Node*> children;
        bool isEnd;
    };

    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char& c : word){
            if(!cur->children.count(c)) cur->children[c] = new Node();
            cur = cur->children[c];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        return dfs(cur, word, 0);
    }

    // dfs processes one characte word[i]
    bool dfs(Node* cur, string& word, int i){
        if(i == word.size()){
        // processed every word already, lets see if this node is the end
            return cur->isEnd;
        }

        // if is '.' we need to try every combination
        char c = word[i];
        if(c == '.'){
            for(auto [nxt, child] : cur->children){
                if(dfs(child, word, i+1)) return true;
            }

            return false; // we tried searching all combination but no such word
        }


        if(!cur->children.count(c)) return false;
        return dfs(cur->children[c], word, i+1);
    }
};
