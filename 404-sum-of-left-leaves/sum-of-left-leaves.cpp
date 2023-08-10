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
int s=0;

    void solve(TreeNode* root,int i){
        if(!root)
        return ;

        if(!root->left and !root->right){
            if(i==1)  //if it is a left child then i=1
            s+=root->val;
            else
            return;
        }

        if(root->left){
            solve(root->left,1); //for left child i=1

        }
        if(root->right){
            solve(root->right,0);  //for right child i=0
        }
    }


    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
        return 0;

        solve(root,0);
        return s;

        
    }
};