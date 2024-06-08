class Solution {
public:
    vector<vector<vector<int>>> dp; // Memoization table

    int solve(vector<int>& v, int k, int ind, int prev) {
        if (ind >= v.size()) return 0;

        if (dp[k][ind][prev + 1] != -1) return dp[k][ind][prev + 1];

        int take = 0, skip = 0, maxi = 0;

        for (int i = ind; i < v.size(); i++) {
            if (prev == -1 || v[i] == v[prev]) {
                take = 1 + solve(v, k, i + 1, i);
            } else {
                if (k > 0) skip = 1 + solve(v, k - 1, i + 1, i);
            }
            maxi = max(maxi, max(take, skip));
        }

        return dp[k][ind][prev + 1] = maxi;
    }

    int maximumLength(vector<int>& nums, int k) {
        if (nums.empty()) return 0;

        int n = nums.size();
        dp.resize(k + 1, vector<vector<int>>(n, vector<int>(n + 1, -1))); // Initialize memoization table

        return solve(nums, k, 0, -1); // Start with prev as -1 for proper initial comparison
    }
};
