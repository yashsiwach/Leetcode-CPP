class Solution {
public:
    bool solve(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind >= nums.size() - 1) {
            return true;  // If we reached or surpassed the last index, return true
        }

        if (dp[ind] != -1) {
            return dp[ind];  // Return cached result
        }

        for (int i = ind + 1; i <= ind + nums[ind] && i < nums.size(); i++) {
            if (solve(nums, i, dp)) {
                return dp[ind] = true;  // Memoize the result as true
            }
        }

        return dp[ind] = false;  // Memoize the result as false
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);  // Memoization table, initialized to -1 (unknown)
        return solve(nums, 0, dp);
    }
};
