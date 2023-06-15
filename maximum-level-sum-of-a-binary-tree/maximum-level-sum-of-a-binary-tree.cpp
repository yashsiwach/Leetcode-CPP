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
    int maxLevelSum(TreeNode* root) {
        if(!root->left && !root->right)return 1;
        int maxi=INT_MIN,ans=0,level=1;
        queue<TreeNode*>q;
        q.push(root);

        //bfs traversal
        while(!q.empty())
        {
            int temp=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                //calculating the sum at current level
                temp+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(temp>maxi)
            {
                maxi=temp;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};