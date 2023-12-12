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
    vector<TreeNode*> preorder(TreeNode* root)
    {
        vector<TreeNode*> ans;
        stack<TreeNode*> st;
        if(root)st.push(root);
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> ans = preorder(root);
        for(int i=0;i<ans.size()-1;i++)
        {
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
        ans[ans.size()-1]->right = NULL;
        ans[ans.size()-1]->left = NULL;
    }
};