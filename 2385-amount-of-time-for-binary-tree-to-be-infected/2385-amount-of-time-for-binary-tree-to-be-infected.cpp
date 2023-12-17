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
    TreeNode* temp = NULL;
    void req(TreeNode* root,int start)
    {
        if(root==NULL) return;
        if(root->val==start)
        {
            temp = root;
            return;
        }
        req(root->left,start);
        req(root->right,start);
    }
    void createHashMap(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m)
    {
        if(root==NULL) return;
        if(root->left) m[root->left] = root;
        if(root->right) m[root->right] = root;
        createHashMap(root->left,m);
        createHashMap(root->right,m);

    }
    int amountOfTime(TreeNode* root, int start) {
        req(root,start);
        unordered_map<TreeNode*,TreeNode*> m;
        createHashMap(root,m);
        unordered_set<TreeNode*> isVisited;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> r;
        r.first = temp;
        r.second = 0;
        q.push(r);
        isVisited.insert(temp);
        int maxValue = INT_MIN;
        while(!q.empty())
        {
            TreeNode* node = (q.front()).first;
            int level = (q.front()).second;
            q.pop();
            if(maxValue<level) maxValue = level;
            if(node && node->left){
                if(isVisited.find(node->left)==isVisited.end())
                {
                    pair<TreeNode*,int> p;
                    p.first = node->left;
                    p.second = level + 1;
                    q.push(p);
                    isVisited.insert(node->left);
                }
            }
            if(node && node->right){
                if(isVisited.find(node->right)==isVisited.end())
                {
                    pair<TreeNode*,int> p;
                    p.first = node->right;
                    p.second = level + 1;
                    q.push(p);
                    isVisited.insert(node->right);
                }
            }
            if(m.find(node)!=m.end())
            {
                if(isVisited.find(m[node])==isVisited.end())
                {
                        pair<TreeNode*,int> p;
                        p.first = m[node];
                        p.second = level + 1;
                        q.push(p);
                        isVisited.insert(m[node]);
                }
            }
        }
        return maxValue;
    }
};