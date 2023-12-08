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
    TreeNode* build(vector<int>& pre,int prelo,int prehi,vector<int>& post,int postlo,int posthi) {
        if(prelo>prehi||postlo>posthi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i=0;
        while(post[i]!=pre[prelo+1])
        {
            i++;
        }
        int lsize = i- postlo + 1;
        int rsize = posthi-i-1;
        root->left = build(pre,prelo+1,prelo+lsize,post,postlo,i);
        root->right = build(pre,prelo+lsize+1,prehi,post,i+1,posthi-1);
        return root;
        
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre,0,pre.size()-1,post,0,post.size()-1);
    }
};