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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
        
    }


    int getDecimalValue(ListNode* head) {
        ListNode* temp = reverseList(head);
        int dec_value = 0;
        int base=1;
        while (temp) { 
            int last_digit = temp->val; 
            dec_value += last_digit * base; 
            base = base * 2; 
            temp = temp->next;
        } 
        return dec_value;

        
    }
};