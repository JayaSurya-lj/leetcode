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
    unordered_map<TreeNode*,int> dp;
    int money(TreeNode* root){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int rll = 0, rlr = 0, rrl = 0, rrr = 0;
        if(root->left) rll += money(root->left->left);
        if(root->left) rlr += money(root->left->right);
        if(root->right) rrl += money(root->right->left);
        if(root->right) rrr += money(root->right->right);
        int take = root->val + rll + rlr + rrl + rrr;
        int leave = money(root->left) + money(root->right);
        return dp[root] = max(take,leave);
    }
    int rob(TreeNode* root) {
        dp.clear();
        return money(root);
    }
};