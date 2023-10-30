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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;
        if(head==NULL)
        {
            while(k>0)
            {
                ans.push_back(NULL);
                k--;
            }
            
            return ans;
        }
        int len = size(head);
        int maxC = len%k;
        int maxSize = len/k + 1;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(100);
        dummy->next = temp;
        int t = k;
        while(maxC!=0 && temp!=NULL)
        {
            ListNode* nest = temp;
            for(int i=1;i<maxSize;i++)
            {
                temp = temp->next;
            }
            nest = temp->next;
            temp->next = NULL;
            ans.push_back(dummy->next);
            dummy->next = nest;
            temp = nest;
            maxC--;
            t--;
        }
        int minC = k-maxC;
        int minSize = len/k;
        while(minC!=0 && temp!=NULL)
        {
            ListNode* nest = temp;
            for(int i=1;i<minSize;i++)
            {
                temp = temp->next;
            }
            nest = temp->next;
            temp->next = NULL;
            ans.push_back(dummy->next);
            dummy->next = nest;
            temp = nest;
            minC--;
            t--;
        }
        if(t!=0)
        {
            while(t>0)
            {
                ans.push_back(NULL);
                t--;
            }
        }
        return ans;
        


        
    }
};