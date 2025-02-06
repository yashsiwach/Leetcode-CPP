class Solution {
public:
void dfs(int node,int p,vector<vector<int>>&adj,int d,int &sum)
{
    sum+=d;
    for(auto it:adj[node])
    {
        if(it!=p){
            dfs(it,node,adj,d+1,sum); 
        }
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& v) {
        vector<int>ans;
        vector<vector<int>>adj(n+1);
        for(auto it:v)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            int sum=0;
            dfs(i,-1,adj,0,sum);
            ans.push_back(sum);
        }
        return ans;
    }
};