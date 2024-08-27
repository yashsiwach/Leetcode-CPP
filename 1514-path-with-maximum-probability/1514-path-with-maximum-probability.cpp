class Solution {
public:
double dfs(int s,int e,unordered_map<int,vector<pair<int,double>>>&mp,vector<bool>&visi)
{
    if(s==e)return 1;
    double ans=0;
    visi[s]=true;
    for(auto it:mp[s])
    {
        if(!visi[it.first])
        {
            double temp=it.second*dfs(it.first,e,mp,visi);
            ans=max(ans,temp);
        }
    }
    return ans;
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        int i=0;
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;
        }
        vector<bool>visi(n,false);
        return dfs(start_node,end_node,adj,visi);
        
    }
};