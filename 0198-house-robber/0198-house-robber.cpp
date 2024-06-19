class Solution {
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i-1];
        }
        return max(dp[n][0],dp[n][1]);
    }
};