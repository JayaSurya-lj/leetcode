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
    void helper(TreeNode* root,vector<vector<int>>& arr,vector<int> ans)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            arr.push_back(ans);
            return;

        }
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> arr;
        vector<int> ans;
        helper(root,arr,ans);
        return arr;
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        vector<vector<int>> path;
        path = pathSum(root);
        for(int i=0;i<path.size();i++)
        {
            int minele = INT_MAX;
            int maxele = INT_MIN;
            for(int j=0;j<path[i].size();j++)
            {
                minele = min(minele,path[i][j]);
                maxele = max(maxele,path[i][j]);
            }
            int diff = abs(maxele - minele);
            ans = max(ans,diff);
        }
        return ans;
    }
};