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
    bool isTargetPresent(TreeNode* root,int target){
        if(root==NULL) return false;
        if(!root->left && !root->right){
            if(root->val==target) return true;
            return false;
        }
        return isTargetPresent(root->left,target) || isTargetPresent(root->right,target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        if(!root->left && !root->right){
            if(root->val==target) return NULL;
        }
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        while(isTargetPresent(root,target)){
            root = removeLeafNodes(root,target);
        }
        return root;
    }
};