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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        if(temp1==NULL && temp2!=NULL) return temp2;
        if(temp2==NULL && temp1!=NULL) return temp1;
        if(temp1==NULL && temp2==NULL) return NULL;
        while(temp1->next!=NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = list2;
        ListNode* head = list1;
        temp1 = head;
        
        while(temp1!=NULL)
        {
            temp2 = temp1->next;
            while(temp2!=NULL)
            {
                int a = temp1->val;
                int b = temp2->val;
                if(a>b)
                {
                    temp1->val = b;
                    temp2->val = a; 

                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return head;
        
    }
};