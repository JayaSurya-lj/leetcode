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
    void helper(TreeNode* root,long long int targetSum,bool& flag)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            {
                flag = true;
            }
            return;

        }

        helper(root->left,targetSum-(root->val),flag);
        helper(root->right,targetSum-(root->val),flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        bool flag = false;
        helper(root,targetSum,flag);
        hasPathSum(root->right,targetSum);
        hasPathSum(root->left,targetSum);
        return flag;
        
    }
};