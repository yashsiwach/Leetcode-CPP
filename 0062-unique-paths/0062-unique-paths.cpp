class Solution {
public:
    // int solve(int m, int n,vector<vector<int>>&dp) {
    //     if (m == 0 && n == 0) {
    //         return 1;
    //     }
    //     if (m< 0 || n < 0) {
    //         return 0;
    //     }
    //     if(dp[m][n]!=-1)return dp[m][n];
    //     int up = solve(m - 1, n,dp);
    //     int down = solve(m, n - 1,dp);
    //     return dp[m][n]=up + down;
    // }
    int solve(int m,int n)
    {
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         for(int i=0;i<=m;i++)
         {
             for(int j=0;j<=n;j++)
             {
                 if (i == 0 && j == 0) {
                    dp[i][j]=1;
                }
                else{
                    int up=0,down=0;
                if(i>0)up = dp[i - 1][j];
                if(j>0)down = dp[i ][j-1];
                dp[i][j]=up + down;
             }}
         }
         return dp[m][n];
    }
    int uniquePaths(int m, int n) {
       
        m--,n--;
        return solve(m, n);
    }
};
