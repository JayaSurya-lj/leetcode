/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int levels(Node* root)
    {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void returnNthLevelElements(Node* root,int level,int curr,vector<Node*>& nums)
    {
        if(root==NULL) return;
        if(curr==level)
        {
            nums.push_back(root);
            return;
        }
        returnNthLevelElements(root->left,level,curr+1,nums);
        returnNthLevelElements(root->right,level,curr+1,nums);
    }
    void traverseLevelOrder(Node* root,vector<vector<Node*>>& arr)
    {
        int level = levels(root);
        for(int i=1;i<=level;i++)
        {
            vector<Node*> v;
            returnNthLevelElements(root,i,1,v);
            arr.push_back(v);
        }
    }
    vector<vector<Node*>> levelOrder(Node* root) {
        vector<vector<Node*>> arr;
        traverseLevelOrder(root,arr);
        return arr;
        
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> arr = levelOrder(root);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size()-1;j++){
                arr[i][j]->next = arr[i][j+1];
            }
        }
        return root;
    }
};