/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    ListNode* temp = head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp==slow) return temp;
        temp = temp->next;
        if(slow==NULL) return NULL;
        slow = slow->next;
    }
    return NULL;
        
    }
};