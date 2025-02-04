class Solution {
private:
    int solveMem(int n,vector<int> &dp)
    {
        if(n<=1) return 1;

        if(dp[n]!=-1) return dp[n];

        int ans=0;
        //think i as root node
        for(int i=1;i<=n;i++)
        {
            ans+=solveMem(i-1,dp)*solveMem(n-i,dp);
        }
        return dp[n]=ans;
    }

public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);

    }
};