struct Node{
    unordered_map<char, Node*> children;
    bool isEnd;
};

class PrefixTree {
Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char& c : word){
            if(!cur->children.count(c)) cur->children[c] = new Node();
            cur = cur->children[c];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char &c : word){
            if(!cur->children.count(c)) return false;
            cur = cur->children[c];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char &c : prefix){
            if(!cur->children.count(c)) return false;
            cur = cur->children[c];
        }

        return true;
        
    }
};
