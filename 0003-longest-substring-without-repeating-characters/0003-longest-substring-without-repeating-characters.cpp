class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int count=0;
        int maxi=0;
        for(int j=0;j<s.length();j++){
            mp.clear();
            count=0;
        for(int i=j;i<s.length();i++)
        {
            if(mp[s[i]]>0)
            {
                mp.clear();
                count=1;
                maxi=max(count,maxi);
                mp[s[i]]++;
                break;
                
            }
            else
            {
                mp[s[i]]++;
                count++;
                maxi=max(count,maxi);
            }
        }
        
        }
        return maxi;
    }
};