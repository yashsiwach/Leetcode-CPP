class Solution {
private:
    const int mod=int(1e9+7);
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //base case
        for(int N=0;N<=n;++N) dp[N][0]=1;
        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % mod;
                dp[N][K] = (dp[N][K] + mod - (K >= N ? dp[N-1][K-N] : 0)) % mod;
            }
        }
        return dp[n][k];
    }
};