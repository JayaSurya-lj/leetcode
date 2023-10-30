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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n=1;
        while(temp!=NULL)
        {
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a) a->next = NULL; //if size of the list is small like 1 or 2 then a is null
        c->next = NULL;
        c = reverseList(b);
        if(a) a->next = c;
        b->next = d;
        if(a) return head; //if size if small then return head or else return c which is actually the point b that is reversed
        return c;

    
        
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp && temp->next)
        {
            int remLen = 0;
            ListNode* t = temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++) //since gap+1 nodes
            {
                t = t->next;
                remLen++;
            }
            if(remLen < gap+1) gap = remLen-1;
            if(gap%2!=0) reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1;i<=gap;i++)
            {
                temp = temp->next;
            }
        }
        return head;
    }
};