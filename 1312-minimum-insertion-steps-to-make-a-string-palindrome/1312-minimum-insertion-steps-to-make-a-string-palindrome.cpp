class Solution {
public:
int dp[501][501];
int rec(int i,int j,string &s)
{
    if(i>=j)return 0;
    int ans=0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])
    {
        ans=rec(i+1,j-1,s);
    }
    else
    {
        ans=1+min(rec(i+1,j,s),rec(i,j-1,s));
    }
    return dp[i][j]=ans;
}
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];

    }
};