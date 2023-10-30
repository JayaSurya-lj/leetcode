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
        int count = len%k;
        int eachSize = len/k;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(100);
        dummy->next = temp;
        int t = k;
        while(t!=0 && temp!=NULL)
        {
            ListNode* nest = temp;
            bool flag = true;
            if(count>0)
            {
                flag = false;
                eachSize++;
                count--;
            }
            for(int i=1;i<eachSize;i++)
            {
                temp = temp->next;
            }
            if(flag==false) eachSize--;
            nest = temp->next;
            temp->next = NULL;
            ans.push_back(dummy->next);
            dummy->next = nest;
            temp = nest;
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