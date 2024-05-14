class Solution {
public:
    int solve(int ind, vector<int>& nums, int prev, vector<vector<int>>& dp) {
        if (ind >= nums.size()) return 0;
        int ans = 0;
        if (dp[ind][prev+1] != -1) return dp[ind][prev+1];
        for (int i = ind; i < nums.size(); i++) {
            if (prev == -1 || nums[i] > nums[prev]) {
                int curr = 1 + solve(i + 1, nums, i, dp); 
                ans = max(ans, curr);
            }
        }
        return dp[ind][prev+1] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(0, nums, -1, dp); 
    }
};