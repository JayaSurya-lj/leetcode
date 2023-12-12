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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) //has three conditions
        {
            if(root->left==NULL && root->right==NULL) // is leaf node
            {
                return NULL;
            }
            if(root->left==NULL || root->right==NULL) // has 1 child
            {
                if(root->left) return root->left;
                if(root->right) return root->right;
            }
            if(root->left!=NULL && root->right!=NULL) // has two childs
            {
                TreeNode* temp = root;
                temp = temp->right;
                while(temp->left!=NULL) //Inorder successor
                {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }

        }
        if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
        }
        if(root->val<key)
        {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};