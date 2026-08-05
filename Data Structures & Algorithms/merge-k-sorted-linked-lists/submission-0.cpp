/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use a min heap of linked lists
        auto comparator = [](const ListNode* a, const ListNode *b){
            return (a->val > b->val);
        };
        // Check syntax if correct anot, also go and find out why this is the syntax, i forgot..
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> minHeap(comparator);
        
        // check if the auto will apply the * automatically {}
        for(auto node : lists){
            if(node) minHeap.push(node);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top(); minHeap.pop();
            cur->next = smallest;
            cur = cur->next;
            smallest = smallest->next;
            if(smallest) minHeap.push(smallest);
        }

        return dummy->next;
    }
};
