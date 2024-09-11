class Solution {
public:
bool solve(vector<int>&nums,int ind,vector<int>&dp)
{
    if(ind>=nums.size()-1)return  true;
    if(dp[ind]!=-1)return dp[ind];
    for(int i=ind+1;i<=ind+nums[ind]&&i<nums.size();i++)
    {
     
        if(solve(nums,i,dp))return true;
    }
    return dp[ind]=false;
}
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
        
    }
};