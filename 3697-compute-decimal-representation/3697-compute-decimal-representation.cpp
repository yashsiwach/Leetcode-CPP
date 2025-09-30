class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long x=1;
        while(n>0){
            long long last=(n%10)*x;
            if(last>0)ans.push_back(last);
            x=x*10;
            n=n/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};