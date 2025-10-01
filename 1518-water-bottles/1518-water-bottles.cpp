class Solution {
public:
    int numWaterBottles(int b, int n) {
        int ans=0;
        while(b>=n)
        {
            b=b-n;
            b++;
            ans+=n;
        }
        ans+=b;
        return ans;
    }
};