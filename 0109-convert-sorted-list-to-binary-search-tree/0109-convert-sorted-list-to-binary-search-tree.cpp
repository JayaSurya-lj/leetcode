/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* letsMakeBST(vector<int>& nums,int left,int right)
    {
        if(left>right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = letsMakeBST(nums,left,mid-1);
        root->right = letsMakeBST(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        return letsMakeBST(nums,left,right);
        

    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        return sortedArrayToBST(nums);
    }
};