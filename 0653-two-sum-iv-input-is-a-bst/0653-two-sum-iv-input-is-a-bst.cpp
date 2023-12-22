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
    void createMap(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL) return;
        mp[root->val]++;
        createMap(root->left,mp);
        createMap(root->right,mp);
    }
    bool findPair(TreeNode* root,unordered_map<int,int>& mp,int k)
    {
        if(root==NULL) return false;
        mp[root->val]--;
        if(mp[root->val]==0) mp.erase(root->val);
        if(mp.find(k-(root->val))!=mp.end())
        {
            return true;
        }
        return findPair(root->left,mp,k)||findPair(root->right,mp,k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        createMap(root,mp);
        return findPair(root,mp,k);
    }
};