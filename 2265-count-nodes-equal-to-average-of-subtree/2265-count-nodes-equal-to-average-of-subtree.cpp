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
    int depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + depth(root->left)+depth(root->right);
    }
    int sum(TreeNode* root)
    {
        if(root==NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void function(TreeNode* root,int& ans)
    {
        if(root==NULL) return;
        int s = sum(root);
        int l = depth(root->left);
        int r = depth(root->right);
        int n = l+r+1;
        int avg;
        if(n==0) avg = root->val;
        else avg = s/n;
        // cout<<avg<<" "<<root->val<<endl;
        if(avg==root->val)
        {
            ans++;
        }
        function(root->left,ans);
        function(root->right,ans);

    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function(root,ans);
        return ans;
    }
};