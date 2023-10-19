class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(auto i:s) 
        {
            if(i=='#'&&a.length()!=0) a.pop_back();
            else if(i!='#') a.push_back(i);
        }
       for(auto i:t) 
        {
            if(i=='#'&&b.length()!=0) b.pop_back();
            else if(i!='#') b.push_back(i);
        }
        cout<<a<<" "<<b<<endl;
        if(a==b)return true ;
        else return false;
    }
};