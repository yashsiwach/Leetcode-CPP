class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind >= nums.size() - 1) {
            return 0;  // Reached the last index, no more jumps needed
        }
        if (dp[ind] != -1) {
            return dp[ind];  // Return the stored result if already computed
        }

        int ans = INT_MAX;
        for (int i = 1; i <= nums[ind] && ind + i < nums.size(); i++) {
            int jumps = solve(ind + i, nums, dp);
            if (jumps != INT_MAX) {  // Only consider valid jumps
                ans = min(ans, 1 + jumps);
            }
        }
        
        return dp[ind] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};
