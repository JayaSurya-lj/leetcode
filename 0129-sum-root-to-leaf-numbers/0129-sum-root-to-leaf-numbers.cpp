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
    void sumHelper(TreeNode* root,int value,int& sum){
        if(root==NULL) return;
        value = value*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum += value;
            return;
        }
        sumHelper(root->left,value,sum);
        sumHelper(root->right,value,sum);


    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumHelper(root,0,sum);
        return sum;
    }
};