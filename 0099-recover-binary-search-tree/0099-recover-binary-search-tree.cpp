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
    void inorder(TreeNode* root,vector<TreeNode*>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]->val>v[j]->val){
                    int temp = v[i]->val;
                    v[i]->val = v[j]->val;
                    v[j]->val = temp;
                }
            }
        }
        
    }
};