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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* nest = NULL;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(100);
        ListNode* temp = dummy;
        while(curr){
            nest = curr->next;
            temp = dummy;
            while(temp->next && temp->next->val<curr->val)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
            curr = nest;
        }
        return dummy->next;
    }
};