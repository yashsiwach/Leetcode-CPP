class Solution {
public:
int solve(string &a,string &b,int n,int m,int i,int j,vector<vector<int>>&dp){
    if(i==n||j==m)return 0;
if(dp[i][j]!=-1)return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j]=1+solve(a,b,n,m,i+1,j+1,dp);
        
    }
    else {
        return dp[i][j]=max(solve(a,b,n,m,i+1,j,dp),solve(a,b,n,m,i,j+1,dp));
    }
    
}
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=solve(a,b,n,m,0,0,dp);
        return ans;
    }
};