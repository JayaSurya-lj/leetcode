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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* odd = new ListNode(100);
        ListNode* even = new ListNode(100);
        ListNode* to = odd;
        ListNode* te = even;
        int idx = 0;
        while(temp!=NULL)
        {
            if((idx)%2==0)
            {
                to->next = temp;
                temp = temp->next;
                to = to->next;
            }
            else
            {
                te->next = temp;
                temp = temp->next;
                te = te->next;
            }
            idx++;
        }
        to->next = even->next;
        te->next = NULL;
        return odd->next;
    }
};