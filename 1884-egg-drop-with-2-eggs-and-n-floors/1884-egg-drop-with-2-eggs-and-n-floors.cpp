class Solution {
public:
    int twoEggDrop(int n) {
         vector<vector<int>> dp(2,vector<int>(n+1,INT_MAX-1));
        dp[0][0]=dp[1][0]=0;
        //BASE CASE 
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=i;
        }   
        // STATE : dp[i][j] means the when we have i egg and j floor what is the minimum no of moves:
        
        for(int at=1;at<=n;at++){
            for(int choose= 1;choose<=at;choose++){
        //TRANSACTION : when we are (at) we through egg it either break or didnt break so
        // if break go to egg-1 if didnt break keep go down  
                dp[1][at]=min(max(dp[0][choose-1],dp[1][at-choose])+1,dp[1][at]);
            }
        }
        return dp[1][n];
    }
};