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
    void solve(vector<int>&v,TreeNode*&root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int maxi=INT_MIN;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp!=nullptr)
                 maxi=max(maxi,temp->val);
                if(temp->left)
                {  
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            v.push_back(maxi);
        }
    }
    vector<int> largestValues(TreeNode* root) {

        vector<int>ans;
        if(root==nullptr)return ans;
        solve(ans,root);
        return ans;
        
    }
};