class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind >= nums.size() - 1) {
            return 0;  // Reached or exceeded the last index
        }

        if (dp[ind] != -1) {
            return dp[ind];  // Return memoized result
        }

        int ans = INT_MAX;
        // Explore all possible jumps from the current index
        for (int i = ind + 1; i <= ind + nums[ind] && i < nums.size(); i++) {
            int num = solve(i, nums, dp);
            if (num != INT_MAX) {
                ans = min(ans, 1 + num);
            }
        }

        return dp[ind] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);  // Memoization table
        return solve(0, nums, dp);
    }
};
