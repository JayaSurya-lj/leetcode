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
        if(root->val==target){
                return true;
        }
        return isTargetPresent(root->left,target) || isTargetPresent(root->right,target);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(!isTargetPresent(root,1)){
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        return root;
        
    }
};