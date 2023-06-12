class Solution {
public:
    bool jatdp(int index,vector<int>&nums,int target,vector<vector<int>>&dp)
    {
        int n= nums.size();
        if(index>=n)
        {
            return 0;
        }
        if(target<0) 
        {
            return 0;
        }
        if(target==0)
        {
            return 1;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool in=jatdp(index+1,nums,target-nums[index],dp);
        bool ex=jatdp(index+1,nums,target,dp);
        dp[index][target]=(ex||in);
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int target=sum/2;
        if(sum&1)
        {
            return false;
        }
         vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        int index=0;
        bool ans =jatdp(index,nums,target,dp);
        return ans;
      

        
    }
};