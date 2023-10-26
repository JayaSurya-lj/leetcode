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
        int c = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = size(head) - n;
        ListNode* temp = head;
        if(idx==0)
        {
            head = head->next;
            return head;
        }
        if(n==1)
        {
            while(temp->next->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next= NULL;
            return head;
        }

        for(int i=1;i<=idx-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
        
    }
};