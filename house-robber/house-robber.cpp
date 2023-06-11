class Solution {
public:
    // int solvedp(vector<int>&nums,int n,vector<int>&dp)
    // {
    //     if(n<0)
    //     {
    //         return 0;
    //     }
    //     if(n==0)
    //     {
    //         return nums[0];
    //     }
    //     if(dp[n]!= -1)
    //     {
    //         return dp[n];
    //     }
    //     int in=solvedp(nums,n-2,dp)+nums[n];
    //     int ex=solvedp(nums,n-1,dp)+0;
    //     dp[n]=max(in,ex);
    //     return dp[n];
    // }
    int tabulation(vector<int>&nums,int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<=n;i++)
        {
            
            int temp=0;
            if(i-2>=0)
            {
                temp=dp[i-2];
            }
            int in=temp+nums[i];
            int ex=dp[i-1]+0;
            dp[i]=max(in,ex);

        }return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
    //     vector<int>dp(n+1,-1);
    //     return solvedp(nums,n,dp);
        return tabulation(nums,n);
    
        
    }
};