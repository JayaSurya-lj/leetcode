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
    ListNode* deleteNode(ListNode* head,int idx)
    {
        ListNode* temp = head;
        int length = size(head);
        if(idx==0)
        {
            head = head->next;
            return head;
        }
        if(idx==length-1)
        {
            for(int i=1;i<=idx-1;i++)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return head;
        }

        for(int i=1;i<=idx-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        int idx = 0;
        while(temp!=NULL)
        {
            bool flag = true;
            if(temp->val==val)
            {
                head = deleteNode(head,idx);
                flag = false;
                temp = head;
                idx = 0;
            }

            if(flag==true)
            idx++;
            if(flag==true)
            temp = temp->next;
        }
        return head;
        
    }
};