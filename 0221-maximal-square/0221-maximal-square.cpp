class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(n == 0 || m == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSquare = 0;

        // Fill the dp table
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        // Base case: first row or first column
                        dp[i][j] = 1;
                    } else {
                        // dp[i][j] is determined by the minimum value of the three neighbors
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Update the maximum square size found
                    maxSquare = max(maxSquare, dp[i][j]);
                }
            }
        }

        // Return the area of the maximum square
        return maxSquare * maxSquare;
    }
};
