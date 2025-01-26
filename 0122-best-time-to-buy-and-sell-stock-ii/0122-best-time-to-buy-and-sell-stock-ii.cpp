class Solution {
public:
int dp[100000];
int solve(vector<int>&v,int ind)
{
    if(ind==v.size())return 0;
    int ans=0;
    if(dp[ind]!=-1)return dp[ind];
    for(int i=ind;i<v.size();i++)
    {
        ans=max(ans,(v[i]-v[ind])+solve(v,i+1));
    }
    return dp[ind]=ans;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),maxi=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<prices.size();i++)
        {
            maxi=max(maxi,solve(prices,i));
        }
        return maxi;
    }
};