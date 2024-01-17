class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(auto &it:arr)mp[it]++;
        for(auto &it:mp)v.push_back(it.second);
        set<int>st(v.begin(),v.end());
        if(st.size()==v.size()){return true;}
        else return false;
        
    }
};