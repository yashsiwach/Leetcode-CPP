class Solution {
public:
    bool solve(int i,int j,string s,string t)
    {
        if(i==s.length())
        {
            return true;
        }
        if(j==t.length()&&i!=s.length()){
            return false;
        }
        if(s[i]==t[j])
        {
            return solve(i+1,j+1,s,t);
        }
        else
        {
            return solve(i,j+1,s,t);  
        }
    }
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        return solve(i,j,s,t);
    }
};