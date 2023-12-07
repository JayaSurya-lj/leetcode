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
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void returnRightSideView(TreeNode* root,vector<int>& ans,int curr)
    {
        if(root==NULL) return;
        ans[curr] = root->val;
        returnRightSideView(root->left,ans,curr+1);
        returnRightSideView(root->right,ans,curr+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        int level = levels(root);
        vector<int> ans(level);
        returnRightSideView(root,ans,0);
        return ans;
    }
};