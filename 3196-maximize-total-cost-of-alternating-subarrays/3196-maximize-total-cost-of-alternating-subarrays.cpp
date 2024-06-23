class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long int n=nums.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(2,0));
       for(long long int i=1;i<=n;i++)
       {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1])+nums[i-1];
            dp[i][1]=dp[i-1][0]+abs(nums[i-1]);
       }
       return max(dp[n][0],dp[n][1]);
    }
};