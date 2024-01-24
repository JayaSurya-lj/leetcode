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
    void checkPalindrome(TreeNode* root,unordered_map<int,int> mp,int& count){
        if(root==NULL) return;
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int m = 1;
            for(auto p:mp){
                int freq = p.second;
                if(freq%2!=0) m--;
                if(m<0) return;
            }
            if(m>=0) count++;
            return;
        }
        checkPalindrome(root->left,mp,count);
        checkPalindrome(root->right,mp,count);

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int count = 0;
        checkPalindrome(root,mp,count);
        return count;
        
    }
};