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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(100);
        ListNode* temp = head;
        for(int i=0;i<lists.size();i++)
        {
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            ListNode* t = lists[i];
            temp->next = t;
        }
        head = head->next;
        ListNode* temp1 = head;
        ListNode* temp2;
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