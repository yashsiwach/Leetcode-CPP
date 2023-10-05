class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int t=floor(n/3);
        vector<int>count;
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto it:mp)
        {
            if(it.second>t) count.push_back(it.first);
        } 
        return count;
    }
};