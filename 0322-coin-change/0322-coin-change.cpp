class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>&dp) {
        if (amount < 0) {
            return -1; // Return -1 to indicate it's not possible to make change.
        }
        if (amount == 0) {
            return 0;
        }
        if(dp[amount]!=INT_MIN)
        {
            return dp[amount];
        }
        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int subproblem = solve(coins, amount - coins[i],dp);
            if (subproblem == -1) {
                continue; 
            }
           ans = min(ans, 1 + subproblem);
        }
        return  dp[amount]=(ans == INT_MAX) ? -1 : ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MIN);
        return solve(coins, amount,dp);
    }
};
