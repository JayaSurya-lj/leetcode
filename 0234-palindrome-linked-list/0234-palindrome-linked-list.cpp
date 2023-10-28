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
    ListNode* reverse(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
        
    }
    bool isPalindrome(ListNode* head) {
        ListNode* a = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) //for left middle
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* b = reverse(slow->next);
        slow->next = b;
        while(b!=NULL)
        {
            cout<<a->val<<" "<<b->val<<endl;
            if(a->val!=b->val) return false;

            a = a->next;
            b = b->next;
        }
        return true;
        
    }
};