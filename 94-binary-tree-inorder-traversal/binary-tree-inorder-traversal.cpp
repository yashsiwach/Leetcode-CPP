
class Solution {
public:
    void solve(vector<int>&v,TreeNode *root)
    {
        if(root==NULL)
        {
            return ;
        }
        solve(v,root->left);
        v.push_back(root->val);
        solve(v,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        solve(v,root);
        return v;
    }
};