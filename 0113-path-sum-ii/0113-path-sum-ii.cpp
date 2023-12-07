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
    void helper(TreeNode* root,vector<vector<int>>& arr,vector<int> ans,int targetSum)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            {
                arr.push_back(ans);
            }
            return;

        }
        helper(root->left,arr,ans,targetSum-(root->val));
        helper(root->right,arr,ans,targetSum-(root->val));
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>> arr;
        vector<int> ans;
        helper(root,arr,ans,targetSum);
        return arr;
        
    }
};