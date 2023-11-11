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
        int c = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* b = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return b;
        
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = reverseList(head);
        int n = size(temp);

        cout<<n;
        vector<int> ans(n,0);
        ans[n-1] = 0;
 
        stack<int> st;
        st.push(temp->val);
        int k = n-1;
        while(temp!=NULL && k>=0)
        {
            while(st.size()>0 && st.top()<=temp->val)
            {
                st.pop();
            }
            if(st.size()==0) ans[k] = 0;
            else ans[k] = st.top();

            st.push(temp->val);
            k--;
            temp = temp->next;
        }

        return ans;

        
    }
};