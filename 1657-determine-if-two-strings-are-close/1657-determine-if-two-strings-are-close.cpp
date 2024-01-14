class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp,mp2;
        for(auto it:word1)mp[it]++;
        for(auto it:word2)mp2[it]++;
        vector<int>v1,v2;
        for(auto it:mp)
        {
            v1.push_back(it.second);
        }
        for(auto it:mp2)v2.push_back(it.second);
        set<char>s1,s2;
        for(auto it:mp)s1.insert(it.first);
        for(auto it:mp2)s2.insert(it.first);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(s1==s2&&v1==v2)return true;
        else return false;

        
    }
};