class Solution {
public:
    int solve(vector<int>&v,int i,vector<int>&dp)
    {
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int opt1=v[i]+solve(v,i+1,dp);
        int opt2=v[i]+solve(v,i+2,dp);
        return dp[i]=min(opt1,opt2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0;
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost ,0,dp),solve(cost,1,dp));
        
    }
};