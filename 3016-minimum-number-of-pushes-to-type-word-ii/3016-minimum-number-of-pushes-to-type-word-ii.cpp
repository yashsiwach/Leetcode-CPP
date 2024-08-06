class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto it:word)mp[it]++;
        int ans=0;
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &p1,auto &p2){return p1.second>p2.second;});
        for(int i=0;i<v.size();i++)
        {
            if(i>=0&&i<=7)
            {
                ans+=mp[v[i].first];
            }
            else if(i>=8&&i<=15)ans+=(mp[v[i].first]*2);
             else if(i>=16&&i<=23)ans+=(mp[v[i].first]*3);
            else ans+=mp[v[i].first]*4;
        }
        return ans;
    }
};