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
    void helper(TreeNode* root,long long int targetSum,long long int& count)
    {
        if(root==NULL) return;
        if(root->val==targetSum)
        {
            count++;
        }
        helper(root->left,targetSum-(root->val),count);
        helper(root->right,targetSum-(root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        long long int count = 0;
        helper(root,targetSum,count);
        count += (pathSum(root->right,targetSum) + pathSum(root->left,targetSum));
        return count;
    }
};