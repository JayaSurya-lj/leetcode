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
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void returnNthLevelElements(TreeNode* root,vector<vector<int>>& arr,int level)
    {
        if(root==NULL) return;
        arr[level].push_back(root->val);
        returnNthLevelElements(root->left,arr,level+1);
        returnNthLevelElements(root->right,arr,level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> arr(n);
        returnNthLevelElements(root,arr,0);
        for(int i=0;i<arr.size();i++)
        {
            if(i%2!=0)
            {
                reverse(arr[i].begin(),arr[i].end());
            }
        }
        return arr;
        
    }
};