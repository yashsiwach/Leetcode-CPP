class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i=0,j=1,count=0,maxi=0;
        int n=s.length();
        if(n==1)return 1;
        while(j<s.length())
        {
            
            if(s[j-1]==s[j])count++;
            while(i<=j&&count>1)
            {
                
                if(s[i]==s[i+1])count--;
                i++;
            }
            maxi=max(maxi,(j-i)+1);
            j++;
        }
        return maxi;
        
    }
};