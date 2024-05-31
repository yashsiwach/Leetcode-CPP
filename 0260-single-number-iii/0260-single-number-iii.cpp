class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int>v;
        for(auto it:mp)
        {
            if(it.second==1)v.push_back(it.first);

        }
        return v;
    }
};