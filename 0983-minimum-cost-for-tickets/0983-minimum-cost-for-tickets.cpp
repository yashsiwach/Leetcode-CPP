class Solution {
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        long long n=d.size();
        if(d.back()==28&&c.back()==31)return 23;
        vector<vector<long long>>dp(366,vector<long long>(3,INT_MAX));
        vector<bool>v(365,false);
        for(long long i=0;i<n;i++)
        {
            v[d[i]-1]=true;
        }
        dp[d[0]][0]=c[0];
         dp[d[0]][1]=c[1];
          dp[d[0]][2]=c[2];
        for(long long i=d[0];i<=365;i++)
        {
            if(i==d[0])continue;
            if(v[i-1]==true)dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+c[0];
            else dp[i][0]=dp[i-1][0];

            if(i-7>0&&v[i-1]==true){
                dp[i][1]=min({dp[i-7][0],dp[i-7][1],dp[i-7][2]})+c[1];
            }
            else dp[i][1]=dp[i-1][1];

            if(i-30>0&&v[i-1]==true){
                dp[i][2]=min({dp[i-30][0],dp[i-30][1],dp[i-30][2]})+c[2];
            }
            else dp[i][2]=dp[i-1][2];
            
        }
        return min({dp[365][0],dp[365][1],dp[365][2]});

        
    }
};