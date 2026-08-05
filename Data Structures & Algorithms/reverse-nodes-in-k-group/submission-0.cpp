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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // key concept here is to reverse in groups
        // so lets start from the first group - reverse the next k elements first before connecting them up
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevEnd = dummy;
        ListNode* curStart = head;
        while(curStart){
            ListNode* curEnd = curStart;
            // Let us first check if there are k nodes
            for(int i=1; i<k; i++){
                if(!curEnd) break;
                curEnd = curEnd->next;
            }
            if(!curEnd) break; // no groups of k to reverse anymore

            ListNode* nextStart = curEnd->next; curEnd->next = nullptr;
            // reverse all the nodes in the current group from start
            ListNode* prev = nullptr;
            ListNode* cur = curStart;
            while(cur){
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }

            // Connect the two tails at the end
            prevEnd->next = curEnd;
            prevEnd = curStart;
            curStart->next = nextStart;
            curStart = nextStart;
        }

        return dummy->next;
    }
};
