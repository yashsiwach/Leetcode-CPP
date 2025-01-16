class Solution {
public:
bool check(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
    else return false;
}
    long long countVowels(string s) {
        long long ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(check(s[i]))
            {
                ans+=(i+1)*(n-i);
            }
        }
        return ans;
    }
};