class Solution {
public:
    int solve(string &s,int i,vector<int>&dp)
    {
        if(i>=s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        int ans1=0,ans2=0;
        if(s[i]-'0'<=26&&s[i]-'0'!=0)
        {
            ans1=solve(s,i+1,dp);
        }
        string temp=s.substr(i,2);
        int to=stoi(temp);

        if(i+1<s.length()&&to<=26&&to!=0&&to>=10)
        {
            ans2=solve(s,i+2,dp);
        }
        return dp[i]=ans2+ans1;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);
        return solve(s,0,dp);
        
        
    }
};