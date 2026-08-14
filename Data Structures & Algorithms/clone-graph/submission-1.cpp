/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> hm;
        dfs(hm, node);
        return hm[node];
    }

    // this function clones the current node and connect to its neighbors
    void dfs(unordered_map<Node*, Node*>& hm, Node* cur){
        if(hm.count(cur)) return; // already cloned before

        hm[cur] = new Node(cur->val);

        // Connect to each neighbour
        for(Node* neigh : cur->neighbors){
            // clone neighbour first
            dfs(hm, neigh);
            hm[cur]->neighbors.push_back(hm[neigh]);
        }
    }
};
