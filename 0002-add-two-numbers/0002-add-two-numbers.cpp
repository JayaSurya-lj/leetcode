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
    long long int reverse(int n)
    {
        long long int c = 0;
        while(n>0)
        {
            c = c*10 + n%10;
            n/=10;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(100);
        ListNode* temp = dummy;
        bool flag = false;
        while(temp1!=NULL || temp2!=NULL)
        {
            int a,b;
            a = 0;
            if(temp1!=NULL) a =temp1->val;

            b = 0;
            if(temp2!=NULL) b = temp2->val;

            int t = a+b;
            int k;
            if(flag==true)
            {
                k = t+1;
                flag = false;

            }
            else k = t;
            if(k>9)
            {
                flag = true;
            }
            cout<<a<<" "<<b<<" "<<t<<" "<<k<<endl;
            ListNode* node = new ListNode(k%10);
            temp->next = node;
            temp = temp->next;

            if(temp1!=NULL)temp1 = temp1->next;
            if(temp2!=NULL)temp2 = temp2->next;

        }
        if(flag==true)
        {
            ListNode* node = new ListNode(1);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
        
    }
};