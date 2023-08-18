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
TreeNode* check(TreeNode* root, int temp) {
    if (!root) {
        return nullptr;
    }
    
    if ((root->left && root->left->val == temp) || (root->right && root->right->val == temp)) {
        return root;
    }
    
    TreeNode* l = check(root->left, temp);
    TreeNode* r = check(root->right, temp);
    
    if (l) {
        return l;
    }
    
    return r;
}


    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        vector<int>tem;
        q.push(root);
        q.push(nullptr);
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==nullptr)
            {
                int flagx=0;
                int flagy=0;
                for(auto i:tem)
                {
                    if(i==x)
                    {
                        flagx=1;
                    }
                    if(i==y)
                    {
                        flagy=1;
                    }
                }
                if(flagx==1&&flagy==1)
                {
                    TreeNode*xc=check(root,x);
                    TreeNode*yc=check(root,y);
                    if(xc!=yc)
                    {
                        return true; 
                    }
                }
                flagx=0;
                flagy=0;
                tem.clear();
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                tem.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return false;
        
    }
};