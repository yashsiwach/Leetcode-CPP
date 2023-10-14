class Solution {
public:
    int n;

    int solve(vector<int>& cost, vector<int>& time, int i, int walls,vector<vector<int>>&dp) {
     
        if (walls <= 0) {
            return 0;
        }

        if (i == n) {
            return 1e9;
        }
        if(dp[i][walls]!=-1)
        {
            return dp[i][walls];
        }
        int opt1 = cost[i] + solve(cost, time, i + 1, walls - 1-time[i],dp);
        int opt2 = solve(cost, time, i + 1, walls,dp);

        return dp[i][walls]=min(opt1, opt2);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int i = 0;
        n = cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(cost, time, 0, n,dp);
    }
};
