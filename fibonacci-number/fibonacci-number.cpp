class Solution {
public:
    int solve(int n,vector<int>&jat)
    {
        if(n==0||n==1)
        {
            return n;
        }
        if(jat[n]!=-1)
        {
            return jat[n];
        }
        jat[n]=solve(n-1,jat)+solve(n-2,jat);
        return jat[n];
    }
    int fib(int n) {
    vector<int>jat(n+1,-1);
    int ad=solve(n,jat);
    return ad;
    }
};