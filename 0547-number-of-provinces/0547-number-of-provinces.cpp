class Solution {
public:
void dfs(vector<bool>&visi,unordered_map<int,vector<int>>&mp,int node)
{
    visi[node]=1;
    for(auto &it:mp[node])
    {
        if(!visi[it])
        {
            dfs(visi,mp,it);
        }
    }
}
    int findCircleNum(vector<vector<int>>& v) {
        unordered_map<int,vector<int>>mp;
        vector<bool>visi(v.size());
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    mp[i+1].push_back(j+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(!visi[i])
            {
                count++;
                dfs(visi,mp,i);
            }
        }
        return count;

    }
};