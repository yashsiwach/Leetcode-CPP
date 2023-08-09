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
    void solve(TreeNode*root,vector<string>&temp,string s)
    {
        if(root==nullptr)
        {
            return ;
        }
        if(s.length()==0)
        {
            s=s+to_string(root->val);
        }
        else{
        s=s+"->"+ to_string(root->val);
        }
        if(root->left==NULL&&root->right==NULL)
        {
            cout<<s<<" ";

            temp.push_back(s);
            return ;
        }
        solve(root->left,temp,s);
        solve(root->right,temp,s);


    }
    vector<string> binaryTreePaths(TreeNode* root) {
      
        vector<string>temp;
        string s;
        solve(root,temp,s);
        return temp;
        

    }
};