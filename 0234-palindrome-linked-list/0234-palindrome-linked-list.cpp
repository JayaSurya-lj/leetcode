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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverse(head->next);
        head->next->next=head;
        head->next = NULL;
        return b;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* c = new ListNode(100);
        ListNode* temp = head;
        ListNode* tc = c;
        while(temp!=NULL)
        {
            ListNode* node = new ListNode(temp->val);
            tc->next = node;
            tc = tc->next;

            temp = temp->next;

        }
        c = c->next;
        ListNode* rev = reverse(c);
        ListNode* t1 = head;
        ListNode* t2 = rev;
        bool flag = true;
        while(t1!=NULL && t2!=NULL)
        {
            cout<<t1->val<<" "<<t2->val<<endl;
            if(t1->val!=t2->val)
            {
                flag = false;
                cout<<"false";
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return flag;
    }
};