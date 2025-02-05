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

TreeNode* rec(map<int,pair<int,int>>&mp,int num)
{
    
    if(num==-1)return nullptr;
    TreeNode* root=new TreeNode(num);
    root->left=rec(mp,mp[num].first);
    root->right=rec(mp,mp[num].second);
    return root;

}
    TreeNode* createBinaryTree(vector<vector<int>>& v) {
        map<int,pair<int,int>>mp;
        set<int>st;
        for(auto it:v)
        {
            st.insert(it[1]);
            st.insert(it[0]);
            if(!mp.count(it[0]))mp[it[0]]={-1,-1};
            if(!mp.count(it[1]))mp[it[1]]={-1,-1};
            if(it[2])mp[it[0]].first=it[1];
            else mp[it[0]].second=it[1];
        }
        for(auto it:v)
        {
            st.erase(it[1]);
        }
        // for(auto it:mp)
        // {
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        if (st.empty()) return nullptr;
        int num=*st.begin();
      //  cout<<num<<endl;
        return rec(mp,num);
        

    }
};