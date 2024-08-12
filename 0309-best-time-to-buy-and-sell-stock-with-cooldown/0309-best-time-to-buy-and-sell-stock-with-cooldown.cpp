class Solution {
public:
    int solve(vector<int>& v, int ind, vector<int>& dp) {
        if (ind >= v.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        // Case 1: Skip the current day
        int skip = solve(v, ind + 1, dp);
        
        // Case 2: Buy on the current day and sell on any subsequent day
        int buyAndSell = 0;
        for (int i = ind + 1; i < v.size(); i++) {
            int profit = (v[i] - v[ind]) + solve(v, i + 2, dp); // i + 2 due to cooldown
            buyAndSell = max(buyAndSell, profit);
        }
        
        dp[ind] = max(skip, buyAndSell);
        return dp[ind];
    }

    int maxProfit(vector<int>& v) {
        vector<int> dp(v.size(), -1);
        return solve(v, 0, dp);
    }
};
