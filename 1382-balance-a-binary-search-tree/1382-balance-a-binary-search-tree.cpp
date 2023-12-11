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
    TreeNode* letsMakeBST(vector<TreeNode*>& nums,int left,int right)
    {
        if(left>right) return NULL;
        int mid = left + (right-left)/2;
        nums[mid]->left = letsMakeBST(nums,left,mid-1);
        nums[mid]->right = letsMakeBST(nums,mid+1,right);
        return nums[mid];
    }
    void inorder(TreeNode* root,vector<TreeNode*>& v)
    {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        return letsMakeBST(v,0,v.size()-1);
        
    }
};