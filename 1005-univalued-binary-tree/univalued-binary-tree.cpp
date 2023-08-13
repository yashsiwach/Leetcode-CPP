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
bool solve(TreeNode*root,int a)
{
    if(root==nullptr)
    {
        return true;
    }
    if(root->val!=a)
    {
        return false;
    }
    bool l=solve(root->left,a);
    bool r=solve(root->right,a);
    return l&&r ;
}
    bool isUnivalTree(TreeNode* root) {
    
        int a=root->val;
        return solve(root,a);

        
    }
};