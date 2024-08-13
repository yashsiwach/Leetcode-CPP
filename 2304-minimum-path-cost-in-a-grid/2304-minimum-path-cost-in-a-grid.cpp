class Solution {
public:
    int solve(int ind, int j, vector<vector<int>>& grid, vector<vector<int>>& mc, int n, int m, vector<vector<int>>& dp) {
        if (ind == n - 1) {
            return grid[ind][j];
        }
        if (dp[ind][j] != -1) return dp[ind][j]; // Memoization check

        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            int val = grid[ind][j];
            int ans = grid[ind][j] + mc[val][i] + solve(ind + 1, i, grid, mc, n, m, dp);
            mini = min(ans, mini);
        }
        return dp[ind][j] = mini; // Store result in dp array
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mc) {
        int n = grid.size(), mini = INT_MAX;
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Initialize dp array

        for (int j = 0; j < m; j++) {
            mini = min(mini, solve(0, j, grid, mc, n, m, dp));
        }

        return mini;
    }
};
