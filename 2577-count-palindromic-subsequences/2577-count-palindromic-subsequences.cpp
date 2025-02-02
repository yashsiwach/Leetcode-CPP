class Solution{
public:
    const int MOD=1e9+7;
    int rec(vector<char>&v,string&s){
        int dp[5]={};
        for(char c:s){
            for(int j=4;j>=0;j--){
                if(c==v[j]) dp[j]=(dp[j]+(j==0?1:dp[j-1]))%MOD;
            }
        }
        return dp[4];
    }
    int countPalindromes(string s){
        int ans=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k++){
                    char a=i+'0',b=j+'0',c=k+'0';
                    vector<char>v={a,b,c,b,a};
                    ans=(ans+rec(v,s))%MOD;
                }
            }
        }
        return ans;
    }
};
