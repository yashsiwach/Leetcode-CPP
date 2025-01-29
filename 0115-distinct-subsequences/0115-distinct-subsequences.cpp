class Solution {
public:
int dp[1001][1001];
int rec(int i,int j,string &s,string &t)
{
    if(i==s.size()||j==t.size())
    {
        if(j==t.size())return 1;
        else return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    ans=rec(i+1,j,s,t);
    if(s[i]==t[j])ans+=rec(i+1,j+1,s,t);
    return dp[i][j]=ans;
}
    int numDistinct(string s, string t) {
        // memset(dp,-1,sizeof(dp));
        // return rec(0,0,s,t);
    const long long MOD = 1e9 + 7;
        long long n=s.size();
        long long m=t.size();
        if (m > n) return 0; 
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for (long long i = 0; i <= n; i++) dp[i][0] = 1; 
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(s[i-1]==t[j-1])dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;

            }
        }
        return (int)dp[n][m];
    }

};