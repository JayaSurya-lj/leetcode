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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(val<root->val && !root->left)
        {
            root->left = new TreeNode(val);
            return root;
        }
        if(val>root->val && !root->right)
        {
            root->right = new TreeNode(val);
            return root;
        }
        if(val<root->val) insertIntoBST(root->left,val);
        else insertIntoBST(root->right,val);
        return root;
    }
};