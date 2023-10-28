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
    ListNode* getNode(ListNode* head,int idx)
    {
        if(head==NULL) return 0;
        int c = 0;
        ListNode* temp = head;
        while(c!=idx && temp!=NULL)
        {
            c++;
            temp = temp->next;
        }

        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        int n = size(head);
        int i=0;
        int j = n-1;
        while(i<j)
        {
            ListNode* left = getNode(head,i);
            ListNode* right = getNode(head,j);
            int t = left->val;
            left->val = right->val;
            right->val = t;
            i++;
            j--;
        }
        return head;
        
    }
};