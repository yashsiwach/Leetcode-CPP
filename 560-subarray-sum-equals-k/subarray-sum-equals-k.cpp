class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int>mp;
        mp[sum]=1;
        for(auto i:nums)
        {
            sum +=i;
            int find=sum-k;
            if(mp.find(find)!=mp.end())
            {
                ans+=mp[find];
            }
            mp[sum]++;
        }
        return ans;

        
    }
};