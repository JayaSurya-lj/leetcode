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
    void leaf(TreeNode* root,vector<int>& v)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        leaf(root->left,v);
        leaf(root->right,v);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        leaf(root1,tree1);
        vector<int> tree2;
        leaf(root2,tree2);
        if(tree1.size()!=tree2.size()) return false;
        for(int i=0;i<tree1.size();i++)
        {
            if(tree1[i]!=tree2[i]) return false;
        }
        return true;

        
    }
};