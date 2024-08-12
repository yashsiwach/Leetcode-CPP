class Solution {
public:
    int minCoins(vector<int>& coins,int amount,int ind,int n,vector<vector<int>>& dp) {
        if(amount < 0 || ind == n) {
            return -1;
        }else if(amount == 0) {
            return 0;
        }
        if(dp[amount][ind]!=INT_MAX)return dp[amount][ind];
        if(coins[ind] <= amount) {
            int take = minCoins(coins,amount - coins[ind],ind,n,dp);
            int notTake = minCoins(coins,amount,ind + 1,n,dp);
            if(take == -1 && notTake == -1)return dp[amount][ind]= -1;
            else if(take != -1 && notTake != -1){
                return dp[amount][ind]=min(1+take,notTake);
            }else if(notTake != -1)return dp[amount][ind]=notTake;
            else if(take != -1)return dp[amount][ind]=1 + take;
        }else {
            return  dp[amount][ind]=minCoins(coins,amount,ind + 1,n,dp);
        }
        return dp[amount][ind]=-1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int> (coins.size() + 1,INT_MAX));
       // vector<int> dp(coins.size(),-1);
        int ans = minCoins(coins,amount,0,coins.size(),dp);
        return ans;
    }
};
