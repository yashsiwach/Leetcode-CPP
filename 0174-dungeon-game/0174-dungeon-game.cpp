class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: minimum HP needed at the princess's cell
        dp[n-1][m-1] = max(1, 1 - v[n-1][m-1]);
        
        // Fill the last row
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - v[i][m-1]);
        }
        
        // Fill the last column
        for (int j = m - 2; j >= 0; j--) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - v[n-1][j]);
        }
        
        // Fill the rest of the dp table
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int down = max(1, dp[i+1][j] - v[i][j]);
                int right = max(1, dp[i][j+1] - v[i][j]);
                dp[i][j] = min(down, right);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<dp[i][j]<<" ";
            
            }
            cout<<endl;
        }
        // The top-left cell will have the minimum initial health required
        return dp[0][0];
    }
};
