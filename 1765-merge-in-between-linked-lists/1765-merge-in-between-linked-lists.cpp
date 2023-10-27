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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int idx = 0;
        ListNode* temp = list1;
        for(int i=1;i<=b+1;i++)
        {
            temp = temp->next;
        }
        ListNode* t = list2;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp = list1;
        for(int i=1;i<=a-1;i++)
        {
            temp = temp->next;
        }
        temp->next = list2;

        return list1;
    }
};