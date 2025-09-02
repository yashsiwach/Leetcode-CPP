class Solution {
public:
map<pair<int,int>,int>mp;
int solve(vector<int>&nums,int ind,int n,int prev){
    if(ind==n)return 0;
    int take=0;
    if(mp.find({prev,ind})!=mp.end())return mp[{prev,ind}];
    // if(dp[prev+1][ind]!=-1)return dp[prev+1][ind];
    if(prev==-1||nums[prev]<nums[ind])take=1+solve(nums,ind+1,n,ind);
    int notTake=solve(nums,ind+1,n,prev);
    return mp[{prev,ind}]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,n,-1);
    }
};