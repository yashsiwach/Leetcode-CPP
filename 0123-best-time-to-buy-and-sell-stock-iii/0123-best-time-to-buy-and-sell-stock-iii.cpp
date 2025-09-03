class Solution {
public:
    int maxProfit(vector<int>& v) {
        int buy1=INT_MIN,buy2=INT_MIN;
        int sell1=0,sell2=0;
        for(int i=0;i<v.size();i++){
            buy1=max(buy1,-v[i]);
            sell1=max(sell1,buy1+v[i]);
            buy2=max(buy2,sell1-v[i]);
            sell2=max(sell2,buy2+v[i]);
        }
        return sell2;
    }
};