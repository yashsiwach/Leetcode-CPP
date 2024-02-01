class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& v,vector<vector<int>> & dp) {
        if (n == 0 && m == 0) return v[0][0];
        if (n < 0 || m < 0) return INT_MAX;
        if(dp[n][m] != 0) return dp[n][m];
       return dp[n][m]=v[n][m]+min(solve(n-1,m,v,dp),solve(n,m-1,v,dp));
    }
    
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size()-1, m = v[0].size()-1;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        return solve(n , m , v,dp);
    }
};
