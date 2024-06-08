class Solution {
public:
int solve(vector<int>&v,int n,int ind,vector<int>&dp)
{
    if(ind>=v.size()||n==0)return 0;
    if(n<0)return INT_MAX-1;
    int take=0,skip=0,mini=INT_MAX;
    if(dp[n]!=-1)dp[n];
    for(int i=ind;i<v.size();i++)
    {
        if(v[i]<=n)
        {
            int temp=1+solve(v,n-v[i],ind,dp);
            if(temp!=INT_MAX)take=temp;
        }
        else break;
        mini=min(mini,take);
    }
    return dp[n]=mini;
}
    int numSquares(int n) {
        vector<int>v;
        vector<int>dp(n+1,-1);
        for(int i=1;i*i<=1e4;i++){
            v.push_back(i*i);
        }
        return solve(v,n,0,dp);
        // vector<vector<int>>v(v.size()+1,vector<int>(n+1,INT_MAX));
        // for(int i=0;i<v.size();i++)
        // {
        //     for(int j=)
        // }
    }
};