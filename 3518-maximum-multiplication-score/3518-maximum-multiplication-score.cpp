class Solution {
public:
   long long maxScore(vector<int>& a, vector<int>& b) {
    int n=b.size();
    vector<vector<long long>> dp(5, vector<long long>(n+1,-1e11));

    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

     for(int i1=1;i1<=4;i1++){
        for(int i2=1;i2<=n;i2++){
            long long int take=-1e11;
            take=dp[i1-1][i2-1]+(long long)a[i1-1]*(long long)b[i2-1];
            long long int not_take=dp[i1][i2-1];

            dp[i1][i2]=max(take,not_take);
        }
    }

    return dp[4][n];
}
};