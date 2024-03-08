class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        int maxi=0;
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        int count=0;
        for(auto it:mp)
        {
            if(it.second==maxi)count++;
        }
        return count*maxi;
        
    }
};