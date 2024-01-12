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
    void findGoodNodes(TreeNode* root,int& count,int maxs){
        if(root==NULL) return;
        if(maxs<=root->val){
            count++;
            cout<<root->val<<" ";
        }
        maxs = max(maxs,root->val);
        findGoodNodes(root->left,count,maxs);
        findGoodNodes(root->right,count,maxs);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        findGoodNodes(root,count,INT_MIN);
        return count;
    }
};