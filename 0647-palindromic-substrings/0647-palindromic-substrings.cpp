class Solution {
public:
bool check (string &s,int i,int j){
    if(i>j)return true;
    bool ans=false;
    if(s[i]==s[j]){
        ans= check(s,i+1,j-1);
    }
    return ans;
}
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,i,j))count++;
            }
        }
        return count;
    }
};