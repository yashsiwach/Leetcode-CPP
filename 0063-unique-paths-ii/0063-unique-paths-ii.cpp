class Solution {
public:
    // int solve(int n,int m,vector<vector<int>>&v,vector<vector<int>>&dp)
    // {
    //     if(n==0&&m==0)return 1;
    //     if(n<0||m<0||v[n][m]==1)return 0;
    //     int up=0,left=0;
    //     if(dp[n][m]!=-1)return dp[n][m];
    //     if(n>0)up=solve(n-1,m,v,dp);
    //     if(m>0)left=solve(n,m-1,v,dp);
    //     return dp[n][m]=up + left;
    // }
    int solve(int m,int n,vector<vector<int>>&v)
    {
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         for(int i=0;i<=m;i++)
         {
             for(int j=0;j<=n;j++)
             {
                if (i == 0 && j == 0)
                {
                    dp[i][j]=1;
                }
                else if (v[i][j]==1)
                {
                    continue;
                }
                else
                {
                    int up=0,down=0;
                    if(i>0)up = dp[i - 1][j];
                    if(j>0)down = dp[i ][j-1];
                    dp[i][j]=up + down;
                }
             }
         }
         return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size()-1,m=v[0].size()-1;

        if(v[0][0]==1||v[n][m]==1)return 0;
        return solve(n,m,v);
    }
};