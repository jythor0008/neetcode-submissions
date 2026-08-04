/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        unordered_map<Node*, Node*> hm;
        while(temp){
            hm[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            Node* copy = hm[temp];
            copy->next = hm[temp->next];
            copy->random = hm[temp->random];
            temp = temp->next;
        }

        return hm[head];
    }
};
