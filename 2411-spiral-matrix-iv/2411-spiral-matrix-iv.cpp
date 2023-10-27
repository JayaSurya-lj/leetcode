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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix (m,vector<int>(n,-1));
        ListNode* temp = head;
        int minr=0,minc=0,maxr=m-1,maxc=n-1;
        int t = 0;
        int tne = m*n;
        while(temp!=NULL && minr<=maxr && minc<=maxc)
        {
            bool flag = true;
            //Right
            for(int j=minc;j<=maxc && t<tne;j++)
            {
                matrix[minr][j]=temp->val;
                temp = temp->next;
                if(temp==NULL)
                {
                    flag = false;
                    break;
                }
                t++;
            }
            if(flag==false) break;
            minr++;
            //down
            for(int i=minr;i<=maxr  && t<tne;i++)
            {
                matrix[i][maxc]=temp->val;
                temp = temp->next;
                if(temp==NULL)
                {
                    flag = false;
                    break;
                }
                t++;
            }
            if(flag==false) break;
            maxc--;
            //left
            for(int j=maxc;j>=minc  && t<tne;j--)
            {
                matrix[maxr][j]=temp->val;
                temp = temp->next;
                if(temp==NULL)
                {
                    flag = false;
                    break;
                }
                t++;
            }
            if(flag==false) break;
            maxr--;
            //top
            for(int i=maxr;i>=minr  && t<tne;i--)
            {
                matrix[i][minc]=temp->val;
                temp = temp->next;
                if(temp==NULL)
                {
                    flag = false;
                    break;
                }
                t++;
            }
            if(flag==false) break;
            minc++;
        }
        return matrix;
    }
};