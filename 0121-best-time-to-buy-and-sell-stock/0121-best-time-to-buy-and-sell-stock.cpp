class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i =0,j=n-1;
        int min = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            if(prices[i]>min){
               profit = max(profit,prices[i]-min);
            }else if (prices[i]<min){
                min = prices[i];
            }else{
                continue;
            }
        }
        cout<<min;
        return profit;
    }
};