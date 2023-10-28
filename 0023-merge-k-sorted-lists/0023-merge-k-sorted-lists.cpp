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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(a!=NULL && b!=NULL)
        {
            if(a->val <= b->val)
            {
                temp->next = a;
                a = a->next;
                temp = temp->next;
               
            }
            else
            {
                temp->next = b;
                b = b->next;
                temp = temp->next;
                
            }
        }
        if(b==NULL)
        {
            temp->next = a;
        }
        if(a==NULL)
        {
            temp->next = b;
        }
        return c->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

        while(lists.size()>1)
        {
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());
            ListNode* c = mergeTwoLists(a,b);
            lists.push_back(c);
        }

        return lists[0];
        
    }
};