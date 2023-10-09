class Solution {
public:
int solve(int n,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+solve(n-i*i,dp));
    }
    return dp[n]=ans;
}
int solve2(int N)
{
    vector<int>dp(N+1,-1);
    dp[N]=0;
   

    for(int n=1;n<=N;n++)
    {
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+dp[n-i*i]);
        };
        dp[n]=ans;
    }
    return dp[N]+1;
}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve2(n);
    }
};