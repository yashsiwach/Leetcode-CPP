class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            if(mp[i]==1)
            return i;
            mp[i]++;
        }
        return -1;
    }
};