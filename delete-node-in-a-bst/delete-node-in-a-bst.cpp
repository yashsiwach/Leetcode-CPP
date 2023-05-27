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
    int maz(TreeNode*root)
    {
    
    
        while(root->right!=nullptr)
        {
            root=root->right;

        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                return NULL;
            }
            else if(root->left!=NULL&&root->right==NULL)
            {
                TreeNode*child=root->left;
                return child;
            }
            else if(root->right!=NULL&&root->left==NULL)
            {
                TreeNode*child=root->right;
                return child;
            }
            else
            {
                int leftmax=maz(root->left);
                
                root->val=leftmax;
                root->left=deleteNode(root->left,leftmax);
                return root;
            }
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        
        return root;
    }
};