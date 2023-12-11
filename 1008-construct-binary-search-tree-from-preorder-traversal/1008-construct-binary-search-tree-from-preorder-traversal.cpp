/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& pre,int prelo,int prehi,vector<int>& in,int inlo,int inhi) {
        if(inlo>inhi && prelo>prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        int i=0;
        for(i=inlo;i<=inhi;i++)
        {
            if(in[i]==pre[prelo]) break;
        }
        int lsize = i- inlo;
        int rsize = inhi-i;
        if(lsize==0) root->left = NULL;
        else root->left = build(pre,prelo+1,prelo+lsize,in,inlo,i-1);
        if(rsize==0) root->right = NULL;
        else root->right = build(pre,prelo+lsize+1,prehi,in,i+1,inhi);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,0,n-1,in,0,n-1);
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};