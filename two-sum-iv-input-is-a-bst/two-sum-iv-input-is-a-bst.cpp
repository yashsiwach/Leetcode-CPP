
class Solution {
public:
void solve(TreeNode*root,vector<int>&jat)
{
    if(root==NULL) return ;
    solve(root->left,jat);
    jat.push_back(root->val);
    solve(root->right,jat);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>jat;
        solve(root,jat);
        int s=0,e=jat.size()-1;
        while(s<e)
        {
            int sum=jat[s]+jat[e];
            if(sum==k) return true;
            if(sum>k) e--;
            else s++;
        }return false;
        
    }
};