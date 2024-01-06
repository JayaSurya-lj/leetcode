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
    void convertToString(TreeNode* root,string& str)
    {
        if(root==NULL){
            return;
        }
        str += '(';
        str += to_string(root->val);
        if(root->right && root->left==NULL){
            str += '(';
            str += ')';
        }
        convertToString(root->left,str);
        convertToString(root->right,str);
        str += ')';
    }
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        string str = to_string(root->val);
        if(root->right && root->left==NULL){
            str += '(';
            str += ')';
        }
        convertToString(root->left,str);
        convertToString(root->right,str);
        return str;
    }
};