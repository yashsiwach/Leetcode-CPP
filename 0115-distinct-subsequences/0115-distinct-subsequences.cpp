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
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);
    }
};