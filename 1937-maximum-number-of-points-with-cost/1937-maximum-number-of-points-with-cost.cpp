class Solution {
public:

    long long maxPoints(vector<vector<int>>& v) {
        long long n = v.size();
        long long m = v[0].size();
        vector<long long> prev(v[0].begin(), v[0].end());
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        for (long long i = 1; i < n; i++) {
            vector<long long> left(m), right(m);
            
            for (long long j = 0; j < m; j++) {
                if (j == 0) {
                    left[j] = prev[j];
                    right[m-j-1] = prev[m-j-1];
                } else {
                    left[j] = max(prev[j], left[j-1] - 1);
                    right[m-j-1] = max(prev[m-j-1], right[m-j] - 1); 
                }
            }
            
            for (long long j = 0; j < m; j++) {
                long long temp=max(left[j], right[j])+v[i][j];
                prev[j] = temp;
                dp[i][j] =temp;
            }
        }
        
        long long ans = 0;
        for (long long i = 0; i < m; i++) {
            ans = max(ans, dp[n-1][i]);
        }
        return ans;
    }
};
