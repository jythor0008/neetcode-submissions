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
    void reorderList(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* fast = temp, *slow = temp;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next; slow->next = nullptr; 
        // At this point we have 2 linked list, represented by second and head/temp
        // Reverse second list
        ListNode* prev = nullptr;
        while(second){
            ListNode* store = second->next;
            second->next = prev;
            prev = second;
            second = store;
        }

        // Merge the two back into one
        ListNode* cur = head;
        while(cur && prev){
            ListNode* temp1 = cur->next;
            ListNode* temp2 = prev->next;
            cur->next = prev;
            prev->next = temp1;
            cur = temp1;
            prev = temp2;
        }
    }
};
