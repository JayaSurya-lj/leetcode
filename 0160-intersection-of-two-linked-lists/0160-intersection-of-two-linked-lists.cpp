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
    int size(ListNode* head)
    {
        int c = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = size(headA);
        int sizeB = size(headB);
        ListNode* tempA;
        ListNode* tempB;
        int k;
        if(sizeA==sizeB)
        {
            tempB = headA;
            tempA = headB;
            while(tempA!=NULL && tempB!=NULL)
            {
                if(tempA==tempB)
                {
                    return tempA;
                }
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return NULL;

        }
        if(sizeA<sizeB)
        {
            tempB = headA;
            tempA = headB;
            k = sizeB - sizeA;
            
        }
        else if(sizeB<sizeA)
        {
            tempB = headB;
            tempA = headA;
            k = sizeA - sizeB; 
        }
        for(int i=1;i<=k;i++)
        {
            if(tempA==NULL) return NULL;
            tempA = tempA->next;
        }

        while(tempA!=NULL && tempB!=NULL)
        {
            if(tempA==tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
        
    }
};