class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int maxi=0,count=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i-1],dp[j]+1);
                }
                else dp[i]=dp[i-1];
            }
        }
        for(auto it:dp)cout<<it<<" ";
        return *max_element(dp.begin(),dp.end());
    }
};