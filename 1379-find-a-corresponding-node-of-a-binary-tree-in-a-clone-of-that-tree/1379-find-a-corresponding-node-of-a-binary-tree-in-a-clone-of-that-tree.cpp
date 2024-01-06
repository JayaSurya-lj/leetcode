/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findClone(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode*& ans) {
        if(original==NULL||cloned==NULL) return;
        if(target==original)
        {
            ans = cloned;
            return;
        }
        findClone(original->left,cloned->left,target,ans);
        findClone(original->right,cloned->right,target,ans);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        findClone(original,cloned,target,ans);
        return ans;
        
    }
};