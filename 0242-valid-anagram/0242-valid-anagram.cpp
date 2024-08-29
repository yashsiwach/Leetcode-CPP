class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto &it:s)mp[it]++;
        for(auto &it:t)
        {
            if(mp.find(it)!=mp.end())
            {
                mp[it]--;

            }
            else return false;
        }
        for(auto &it:mp)if(it.second!=0)return false;
        return true;
        
    }
};