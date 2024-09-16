class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp)if(it.second==2)ans.push_back(it.first);
        return ans;
    }
};