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
    TreeNode* build(vector<int>& in,int inlo,int inhi,vector<int>& post,int postlo,int posthi) {
        if(inlo>inhi && postlo>posthi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        int i=0;
        for(i=inlo;i<=inhi;i++)
        {
            if(in[i]==post[posthi]) break;
        }
        int lsize = i- inlo;
        int rsize = inhi-i;
        if(lsize==0) root->left = NULL;
        else root->left = build(in,inlo,i-1,post,postlo,postlo+lsize-1);
        if(rsize==0) root->right = NULL;
        else root->right = build(in,i+1,inhi,post,postlo+lsize,posthi-1);

        return root;
        
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in,0,n-1,post,0,n-1);
        
    }
};