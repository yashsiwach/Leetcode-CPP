class Solution {
public:
int dp[26][503][503];
    int solve(vector<int>& v, int k, int ind, int prev) {
        if (ind >= v.size()) return 0;

        int take = 0, skip = 0, maxi = 0;
        if(dp[k][ind][prev]!=-1)return dp[k][ind][prev];
        for (int i = ind; i < v.size(); i++) {
            if (ind == 0 || v[i] == v[prev]) {
                take = 1 + solve(v, k, i + 1,i); // Corrected: i + 1
            } else {
                if(k>0)skip = 1 + solve(v, k - 1, i + 1, i); // Corrected: i + 1
            }
            maxi = max(maxi, max(take, skip));
        }
        
        return dp[k][ind][prev]=maxi;
    }

    int maximumLength(vector<int>& nums, int k) {
memset(dp,-1,sizeof(dp));
        if (nums.empty()) return 0; // Added check for empty array
        return solve(nums, k, 0, nums[0]); // Correct initial call
    }
};
