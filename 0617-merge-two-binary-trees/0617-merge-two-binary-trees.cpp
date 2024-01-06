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
    void constructTree(TreeNode* root,TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL) return;
        int val = 0;
        if(root1) val += root1->val;
        if(root2) val += root2->val;
        root->val = val;
        if((root1 && root1->left )||(root2 && root2->left))
        {
            root->left = new TreeNode(0);
            TreeNode* first = NULL;
            TreeNode* second = NULL;
            if(root1) first = root1->left;
            if(root2) second = root2->left;
            constructTree(root->left,first,second);
        }
        if((root1 && root1->right )||(root2 && root2->right))
        {
            root->right = new TreeNode(0);
            TreeNode* first = NULL;
            TreeNode* second = NULL;
            if(root1) first = root1->right;
            if(root2) second = root2->right;
            constructTree(root->right,first,second);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;
        TreeNode* root = new TreeNode(0);
        root->right = new TreeNode(0);
        constructTree(root->right,root1,root2);
        return root->right;

    }
};