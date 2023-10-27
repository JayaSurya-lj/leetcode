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
    ListNode* swapNodes(ListNode* head, int k) {
        int a,b;
        ListNode* temp = head;
        for(int i=1;i<=k-1;i++)
        {
            temp = temp->next;
        }
        a = temp->val;
        ListNode* temp2 = head;
        int length = size(head);
        int t = length-k+1;
        for(int i=1;i<=t-1;i++)
        {
            temp2 = temp2->next;
        }
        b = temp2->val;

        temp->val = b;
        temp2->val = a;

        return head;
        
    }
};