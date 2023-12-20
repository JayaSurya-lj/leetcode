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
    int returnmax(vector<int>& nums,int lo,int hi)
    {
        int maxs = INT_MIN;
        for(int i=lo;i<=hi;i++)
        {
            maxs = max(maxs,nums[i]);
        }
        return maxs;
    }
    TreeNode* constructTree(vector<int>& nums,int lo,int hi)
    {
        if(lo==hi){
            TreeNode* node = new TreeNode(nums[lo]);
            return node;
        }
        if(lo>hi) return NULL;
        int maxs = returnmax(nums,lo,hi);
        int i;
        for(i=lo;i<=hi;i++)
        {
            if(nums[i]==maxs) break;
        }
        TreeNode* root = new TreeNode(maxs);
        int lsize = i-lo;
        int rsize = hi-i;
        if(lsize) root->left = constructTree(nums,lo,i-1);
        if(rsize) root->right = constructTree(nums,i+1,hi);

        return root;


    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return constructTree(nums,0,n-1);
        
    }
};