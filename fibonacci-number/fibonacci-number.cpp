class Solution {
public:
    //Top down (recursion + Memorization)
    // int solve(int n,vector<int>&jat)
    // {
    //     if(n==0||n==1)
    //     {
    //         return n;
    //     }
    //     if(jat[n]!=-1)
    //     {
    //         return jat[n];
    //     }
    //     jat[n]=solve(n-1,jat)+solve(n-2,jat);
    //     return jat[n];
    // }

    int bottomup(int n){
        vector<int>dp(n+1,-1);
        dp[0]=0;
        
        if(n==0) return dp[0];
        dp[1]=1;
        if(n==1) return dp[1];
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
    //vector<int>jat(n+1,-1);
    //int ad=solve(n,jat);
    //return ad;
    return bottomup(n);

    }
};