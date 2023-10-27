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
    int size(ListNode* head)
    {
        if(head==NULL) return 0;
        int c = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }

        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int length = size(head);
        if(length==0) return NULL;
        k = k%length;
        int t = length - k-1;
        ListNode* a = head;
        for(int i=1;i<=t;i++)
        {
            a = a->next;
        }
        
        ListNode* b = head;
        while(b->next!=NULL)
        {
            b = b->next;
        }
        b->next = head;
        head = a->next;
        a->next = NULL;

        return head;
        
    }
};