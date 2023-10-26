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
    ListNode* middleNode(ListNode* head) {
        int total = size(head);
        if(total==1) return head;
        ListNode* temp = head;
        int req = total/2;
        int c = 0;
        while(c!=req && temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        return temp;

    }
};