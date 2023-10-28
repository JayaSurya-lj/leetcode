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
    ListNode* reverse(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
        
    }
    void reorderList(ListNode* head) {
        ListNode* a = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) //for left middle
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* b = reverse(slow->next);
        slow->next = NULL;
        int i=0;
        ListNode* temp1 = head;
        ListNode* temp2 = b;
        ListNode* ans = new ListNode(100);
        ListNode* temp = ans;
        while(temp1!=NULL && temp2!=NULL)
        {

                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;

                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
        }
        temp->next = temp1;

    }
};