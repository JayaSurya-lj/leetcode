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
    int sum(TreeNode* root)
    {
        if(root==NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        int lsum = sum(root->left);
        int rsum = sum(root->right);
        return abs(lsum-rsum) + findTilt(root->left) + findTilt(root->right);
        
    }
};