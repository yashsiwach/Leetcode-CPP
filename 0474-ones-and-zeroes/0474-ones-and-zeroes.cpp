class Solution {
public:
    int solve(vector<pair<int, int>>& v, int zero, int one, int ind, vector<vector<vector<int>>>& dp) {
        if (ind == v.size())
            return 0;

        if (dp[ind][zero][one] != -1)
            return dp[ind][zero][one];

        int p = 0;

        if (v[ind].first <= zero && v[ind].second <= one) {
            p = 1 + solve(v, zero - v[ind].first, one - v[ind].second, ind + 1, dp);
        }
        int np = solve(v, zero, one, ind + 1, dp);

        return dp[ind][zero][one] = max(p, np);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v;
        for (auto it : strs) {
            int zero = 0;
            sort(it.begin(), it.end());
            for (int i = 0; i < it.size(); i++) {
                if (it[i] == '1')
                    break;
                zero++;
            }
            int ones = it.size() - zero;
            v.push_back({zero, ones});
        }

        vector<vector<vector<int>>> dp(v.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(v, m, n, 0, dp);
    }
};
