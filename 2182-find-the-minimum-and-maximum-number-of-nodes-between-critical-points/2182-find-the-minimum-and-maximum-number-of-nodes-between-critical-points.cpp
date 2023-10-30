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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        if(head == NULL||head->next==NULL||head->next->next==NULL)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        vector<int> cnodes;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nest = curr->next;
        int c = 1;
        while(nest!=NULL)
        {
            if(curr->val>prev->val && curr->val>nest->val)
            {
                cnodes.push_back(c);
            }
            else if(curr->val<prev->val && curr->val<nest->val)
            {
                cnodes.push_back(c);
            }
            prev = prev->next;
            curr = curr->next;
            nest = nest->next;
            c++;
        }

        if(cnodes.size()<2)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int minValue = INT_MAX;
        for(int i=0;i<cnodes.size()-1;i++)
        {
            int value = cnodes[i+1]-cnodes[i];
            if(value<minValue) minValue = value;
        }

        int maxValue = -1;

        maxValue = cnodes[cnodes.size()-1]-cnodes[0];

        ans.push_back(minValue);
        ans.push_back(maxValue);
        return ans;
        
    }
};