class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=INT_MAX;
        }
        dp[1][0]=v[0];
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=min(dp[i-1][0],v[i-1]);
            dp[i][1]=max(dp[i-1][1],v[i-1]-dp[i-1][0]);
           // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        return dp[n][1];
    }
};