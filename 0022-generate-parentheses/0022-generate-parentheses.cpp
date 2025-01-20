class Solution {
public:

void solve(int i,int n,vector<string>&ds,string s)
{
    if(i==n)
    {
        ds.push_back(s);
        return;
    }
    s.push_back('(');
    solve(i+1,n,ds,s);
    s.pop_back();
    s.push_back(')');
    solve(i+1,n,ds,s);

}
bool check(string &s)
{
    int open=0;
    for(auto it:s)
    {
        if(it=='(')open++;
        else open--;
        if(open<0)break;
    }
    if(open==0)return true;
    else return false;
}
    vector<string> generateParenthesis(int n) {
       n=n*2;
    vector<string>ds;
    string s;
    solve(0,n,ds,s);
//    print(ds);
    vector<string>ans;
    for(auto it:ds)
    {
        if(check(it))ans.push_back(it);
    }
   // print(ans);
   return ans; 
    }
};