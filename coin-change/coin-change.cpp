class Solution {
public:
    // int solve(vector<int>&coins,int amount,vector<int>&jat)
    // {
    //     if(amount==0)
    //     {
    //         return 0;
    //     }
    //     if(amount<0)
    //     {
    //         return INT_MAX;
    //     }
    //     if(jat[amount]!=-1)
    //     {
    //         return jat[amount];
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++)
    //     {
    //         int ans=solve(coins,amount-coins[i],jat);
    //         if(ans!=INT_MAX)
    //         {
    //             mini=min(1+ans,mini);
    //         }
    //     }
    //     jat[amount]=mini;
    //     return jat[amount];
    // }
    int solve(vector<int>&coins,int amount)
    {
        vector<int>jat(amount+1,INT_MAX);
        jat[0]=0;
        for(int i=1;i<=amount;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++)
        {       if(i-coins[j]>=0){
                  int ans=jat[i-coins[j]];
                  if(ans!=INT_MAX)
                  {
                      mini=min(1+ans,mini);
                  }
        }
        }
        jat[i]=mini;
        }return jat[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
     
        int ans= solve(coins,amount);
        if(ans==INT_MAX)
        {
            return -1;
        }
        else return ans;
        
    }
};