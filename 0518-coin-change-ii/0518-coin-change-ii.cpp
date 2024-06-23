class Solution {
public:
    int change(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // There is one way to make a sum of 0 (using no coins)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i-1][j]; // Exclude the current coin
                if (j - v[i-1] >= 0) {
                    dp[i][j] += dp[i][j - v[i-1]]; // Include the current coin
                }
            }
        }
        
        return dp[n][k];
    }
};
