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
    void fillFrequency(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL) return;
        mp[root->val]++;
        fillFrequency(root->left,mp);
        fillFrequency(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        fillFrequency(root,mp);
        int maxFreq = INT_MIN;
        for(auto p:mp)
        {
            int freq = p.second;
            maxFreq = max(maxFreq,freq);
        }
        vector<int> v;
        for(auto p:mp)
        {
            if(p.second==maxFreq) v.push_back(p.first);
        }
        return v;
    }
};