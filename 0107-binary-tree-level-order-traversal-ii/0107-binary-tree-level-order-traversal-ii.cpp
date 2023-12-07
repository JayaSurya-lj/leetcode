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
        return 1 + max(levels(root->left), levels(root->right));
    }
    void returnNthLevelElements(TreeNode* root,vector<vector<int>>& arr,int level,int n)
    {
        if(root==NULL) return;
        arr[n-level-1].push_back(root->val);
        returnNthLevelElements(root->left,arr,level+1,n);
        returnNthLevelElements(root->right,arr,level+1,n);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> arr(n);
        returnNthLevelElements(root,arr,0,n);
        return arr;
        
    }
};