struct Node {
    Node *next, *prev;
    int key;
    int val;

    Node(){}

    Node(int key, int value) : key(key), val(value) {}
};

class LRUCache {
    // LRU cache, we should use a map of key to value map
    // Also use a doubly linked list to quickfind least recently used nodes
    unordered_map<int, Node*> hm;
    Node* least;
    Node* most;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;    
        least = new Node();
        most = new Node();
        least->next = most;
        most->prev = least;
    }
    
    void remove(Node* cur){
        Node* nxt = cur->next;
        Node* pre = cur->prev;
        nxt->prev = pre;
        pre->next = nxt;
    }

    void insert(Node* cur){
        Node* pre = most->prev;
        pre->next = cur;
        most->prev = cur;
        cur->next = most;
        cur->prev = pre;
    }

    int get(int key) {
        if(!hm.count(key)) return -1;

        Node* cur = hm[key];
        remove(cur);
        insert(cur);
        return hm[key]->val;
    }
    
    void put(int key, int value) {
        if(hm.count(key)){
            Node* cur = hm[key];
            cur->val = value;
            remove(cur);
            insert(cur);
            return;
        }

        if(hm.size() == cap){
            // remove LRU
            Node* rem = least->next;
            remove(rem);
            hm.erase(rem->key);
        }

        Node* cur = new Node(key, value);
        hm[key] = cur;
        insert(cur);
    }
};
