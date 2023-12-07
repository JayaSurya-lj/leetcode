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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* tempR = root->right;
        TreeNode* tempL = root->left;
        root->left = tempR;
        root->right = tempL;
        invertTree(root->left);
        invertTree(root->right);
        return root;
         
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val!=q->val) return false;
        bool l = isSameTree(p->left,q->left);
        if(l==false) return false;
        bool r = isSameTree(p->right,q->right);
        if(r==false) return false;
        return true;
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        invertTree(root->left);
        bool flag = isSameTree(root->left,root->right);
        invertTree(root->left);
        return flag;

        
    }
};