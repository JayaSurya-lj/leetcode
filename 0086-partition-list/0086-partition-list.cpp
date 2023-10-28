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
    ListNode* partition(ListNode* head, int x) {
        ListNode* c = new ListNode(100);
        ListNode* t = c;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                ListNode* a = new ListNode(temp->val);
                t->next = a;
                t = t->next;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            if(temp->val>=x)
            {
                ListNode* a = new ListNode(temp->val);
                t->next = a;
                t = t->next;
            }
            temp = temp->next;
        }
        return c->next;
        
    }
};