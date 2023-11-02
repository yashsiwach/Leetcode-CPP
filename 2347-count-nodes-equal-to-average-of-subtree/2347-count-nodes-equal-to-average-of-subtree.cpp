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
int n=0;
    pair<int,int> solve(TreeNode*&root)
    {
        if(root==nullptr)return {0,0};
       // if(root->left==nullptr&&root->right==nullptr)return {root->val,1};
        pair<int,int>p1={0,0};
        pair<int,int>p2={0,0};
        if(root->left)p1=solve(root->left);
        if(root->right)p2=solve(root->right);
        int sum=root->val+p1.first+p2.first;
        int nums=p1.second+p2.second+1;
        cout<<sum<<" "<<nums<<endl;
        if(sum/nums==root->val)n++;
        return {sum,nums};
        
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return n;
        
    }
};