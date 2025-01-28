class Solution {
public:
bool solve(string &s,string p,int i,int j)
{
    // base case
    // (s)i and (p)j sath me bahar -> true
    // (p)j bahar hai (s)i bacha hai -> false
    // (s)i bhar (p)j bacha hai -> jitne bhi bache j hai woh * -> true else false

    // case 1 match
    // case 2 j == ? return solve(i+1,j+1)
    // case 3 j == * return solve(i+1,j) || solve(i,j+1)
    // else return false

    if(j==p.length()&&i!=s.length())
    {
        return false;
    }
    if(i==s.length()&&j==p.length()) return true;
    if(i==s.length()&&j!=p.length()) 
    {
        for(auto it=p.begin()+j;it!=p.end();it++)
        {
            if(*it!='*') return false;
        }
        return true;
    }
    if(s[i]==p[j] ||p[j]=='?') {
        return solve(s,p,i+1,j+1);
    }
    else
    {
       if(p[j]=='*')
       {
           return solve(s,p,i+1,j) || solve(s,p,i,j+1);
       }
       else return false;
    }

    
}
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
        
    }
};