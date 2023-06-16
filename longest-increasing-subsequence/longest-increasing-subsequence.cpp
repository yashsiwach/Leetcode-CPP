class Solution {
public:
    int solve(vector<int>&jat,int curr,int pre,vector<vector<int>>&dp)
    {
        if(curr>=jat.size()) return 0;
        int in=0;
        if(dp[curr][pre+1]!=-1) return dp[curr][pre+1];
        if(pre==-1|| jat[curr]>jat[pre])
        {
            in=1+solve(jat,curr+1,curr,dp);
        }
        int ex=solve(jat,curr+1,pre,dp);
        dp[curr][pre+1]=max(in ,ex);
        return dp[curr][pre+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int n=nums.size();
        int pre=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans= solve(nums,curr,pre,dp);
        return ans;
        
    }
};