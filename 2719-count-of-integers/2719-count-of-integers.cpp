class Solution {
public:
long long dp[2][25][501];
long long MOD=1e9+7;
long long rec(long long tight,string &s,long long ind,long long sum,long long mini,long long maxi)
{
    if (sum>maxi) return 0;
    if(ind==s.size())return (sum>=mini&&sum<=maxi);
    if(dp[tight][ind][sum]!=-1)return dp[tight][ind][sum];
    long long bound=tight?(s[ind]-'0'):9;
    long long ans=0;
    for(long long i=0;i<=bound;i++)
    {
        long long nb=(tight&&(i==bound));
        ans=(ans+rec(nb,s,ind+1,sum+i,mini,maxi))%MOD;
    }
    return dp[tight][ind][sum]=ans;
}
    int count(string num1, string num2, int mini, int maxi) {
        string a=to_string(stoll(num1)-1);
        string b=num2;
        memset(dp,-1,sizeof(dp));
        int high=rec(1,b,0,0,mini,maxi);
        memset(dp,-1,sizeof(dp));
        int low=rec(1,a,0,0,mini,maxi);
        return (high-low+MOD)%MOD;
    }
};