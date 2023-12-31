class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int,int>mp;
        int i=0,maxi=0;
        set<char>st(s.begin(),s.end());
        if(st.size()==s.length())return -1;
        while(i<s.length())
        {
            if(mp.find(s[i])!=mp.end())
            {
                 maxi=max(maxi,(i-mp[s[i]])-1);
             
            }
            else 
            {
              
              mp[s[i]]=i;
            }
            i++;

        }
        
        return maxi;
         
    }
};