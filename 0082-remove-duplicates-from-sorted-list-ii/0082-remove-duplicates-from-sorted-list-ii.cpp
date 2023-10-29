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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        while(curr and curr->val==val)
        {
            curr = curr->next;
        }
        head = curr;

        while(curr)
        {
            if(curr->next and curr->next->val==val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
        
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->val==temp->next->val)
            {
               head = removeElements(head,temp->val);
            }
            temp = temp->next;
        }
 
        return head;
        
    }
};