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
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* a = reverseList(head);
        ListNode* temp = a;
        int num = 0;
        int base = 1;
        while(temp!=NULL)
        {
            int k = temp->val;
            num = num + (base*k);
            base *= 2;

            temp = temp->next;
        }
        return num;
        
    }
};