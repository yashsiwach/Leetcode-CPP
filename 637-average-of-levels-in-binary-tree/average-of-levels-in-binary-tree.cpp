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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        vector<int>tem;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            // cout<<temp->val<<" ";
            if(temp==NULL)
            {
                double avg=0;
                double size=tem.size();
                double sum=0;
                for(auto i:tem)
                {
                    sum=sum+i;
                }
                avg=sum/size;
                v.push_back(avg);
                tem.clear();
                cout<<endl;
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
            }
            else
                {
                    
                    tem.push_back(temp->val);
                    cout<<temp->val<<endl;
                     if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
           

        }
        return v;
        
    }
};