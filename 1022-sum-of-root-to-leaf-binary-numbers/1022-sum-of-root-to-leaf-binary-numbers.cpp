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
    int binaryVectorToInteger(const vector<int>& binaryVector) {
        int decimalInteger = 0;

        for (int bit : binaryVector) {
            decimalInteger = (decimalInteger << 1) | bit;
        }

        return decimalInteger;
    }
    void preorder(TreeNode* root,vector<vector<int>>& binary,vector<int> num)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            num.push_back(root->val);
            binary.push_back(num);
            return;
        }
        num.push_back(root->val);
        preorder(root->left,binary,num);
        preorder(root->right,binary,num);

    }
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> binary;
        preorder(root,binary,{});
        vector<int> nums;
        for(int i=0;i<binary.size();i++)
        {
            vector<int> num = binary[i];
            nums.push_back(binaryVectorToInteger(num));

        }
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        return sum;
    }
};