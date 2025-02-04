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
void rec(TreeNode* root,int t,int sum,vector<vector<int>>&ans,vector<int>&v)
{
    if(!root)return;
    v.push_back(root->val);
    sum+=root->val;
    if(!root->left&&!root->right)if(sum==t)ans.push_back(v);
     
    rec(root->left,t,sum,ans,v);
    rec(root->right,t,sum,ans,v);
 
    v.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(root,t,0,ans,temp);
        return ans;
    }
};