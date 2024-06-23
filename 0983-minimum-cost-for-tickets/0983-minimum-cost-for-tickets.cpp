class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);  // dp[i] will be the minimum cost to cover travel up to day i
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int i = 1; i <= 365; ++i) {
            if (travelDays.count(i) == 0) {
                dp[i] = dp[i-1];
            } else {
                int cost1 = dp[i-1] + costs[0];  // 1-day pass
                int cost7 = dp[max(0, i-7)] + costs[1];  // 7-day pass
                int cost30 = dp[max(0, i-30)] + costs[2];  // 30-day pass
                dp[i] = min({cost1, cost7, cost30});
            }
        }

        return dp[365];
    }
};
